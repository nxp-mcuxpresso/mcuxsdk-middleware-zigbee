package com.jennic.ZPSConfiguration.provider.util;

import java.math.BigInteger;
import java.util.Collection;
import java.util.Iterator;

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.ActiveEpServer;
import com.jennic.ZPSConfiguration.BindRequestServer;
import com.jennic.ZPSConfiguration.BindUnbindServer;
import com.jennic.ZPSConfiguration.BindingTable;
import com.jennic.ZPSConfiguration.ChannelMask;
import com.jennic.ZPSConfiguration.ChildNodes;
import com.jennic.ZPSConfiguration.Cluster;
import com.jennic.ZPSConfiguration.Coordinator;
import com.jennic.ZPSConfiguration.DefaultNwkKey;
import com.jennic.ZPSConfiguration.DefaultServer;
import com.jennic.ZPSConfiguration.DeviceAnnceServer;
import com.jennic.ZPSConfiguration.EndDevice;
import com.jennic.ZPSConfiguration.EndDeviceBindServer;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.IeeeAddrServer;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.MatchDescServer;
import com.jennic.ZPSConfiguration.MgmtLeaveServer;
import com.jennic.ZPSConfiguration.MgmtLqiServer;
import com.jennic.ZPSConfiguration.MgmtNWKUpdateServer;
import com.jennic.ZPSConfiguration.MgmtRtgServer;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NodeDescServer;
import com.jennic.ZPSConfiguration.NwkAddrServer;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.PermitJoiningServer;
import com.jennic.ZPSConfiguration.PowerDescServer;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.Router;
import com.jennic.ZPSConfiguration.SimpleDescServer;
import com.jennic.ZPSConfiguration.SystemServerDiscoveryServer;
import com.jennic.ZPSConfiguration.TrustCenter;
import com.jennic.ZPSConfiguration.ZDOClientServer;
import com.jennic.ZPSConfiguration.ZDOServersCoordinator;
import com.jennic.ZPSConfiguration.ZDOServersEndDevice;
import com.jennic.ZPSConfiguration.ZDOServersRouter;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZdoClient;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;
import com.jennic.ZPSConfiguration.impl.ZPSConfigurationFactoryImpl;


public class ZigbeeWirelessNetworkChildEnricher {
	
	ZigbeeWirelessNetwork zwn;
	
	public ZigbeeWirelessNetworkChildEnricher(ZigbeeWirelessNetwork owner) {
		zwn = owner;
	}
	
	public void enrich(Collection<?> collection) {
		ZPSConfigurationFactory factory = new ZPSConfigurationFactoryImpl();
		for (Object o : collection) {
			if(o instanceof Node) {
				enrich(factory,(Node)o) ;
			}
			if(o instanceof Coordinator) {
				enrichCoordinator(factory,(Coordinator)o) ;				
			} else if (o instanceof Router) {
				enrichRouter(factory,(Router)o) ;
			} else if (o instanceof EndDevice) {
				enrichEndDevice(factory,(EndDevice)o) ;
			}
		}		
	}
	
	public void enrich(Node x) {
		ZPSConfigurationFactory factory = new ZPSConfigurationFactoryImpl();
		enrich(factory,x) ;
		if(x instanceof Coordinator) {
			enrichCoordinator(factory,(Coordinator)x) ;				
		} else if (x instanceof Router) {
			enrichRouter(factory,(Router)x) ;
		} else if (x instanceof EndDevice) {
			enrichEndDevice(factory,(EndDevice)x) ;
		}
	}
	
	private void enrich(ZPSConfigurationFactory factory, Node x) {

		APDU a = null;

		if(x.getPDUConfiguration() == null) {
			a = factory.createAPDU();
			PDUManager m = factory.createPDUManager();
			a.setName("apduZDP");
			a.setSize(100);
			a.setInstances(4);
			a.setPDUConfig(m);
			x.setPDUConfiguration(m);
		} else {
			for (Iterator<APDU> iterator = x.getPDUConfiguration().getAPDUs().iterator(); iterator.hasNext();) {
				APDU ia = (APDU) iterator.next();
				
				if (0 == ia.getName().compareTo("zpduZDP")) {
					a = ia;
					break;
				}
			}
		}
	
		if(x.getNodeDescriptor() == null) {
			x.setNodeDescriptor(factory.createNodeDescriptor()) ;
		}
		
		if(x.getNodePowerDescriptor() == null) {
			x.setNodePowerDescriptor(factory.createNodePowerDescriptor()) ;
		}

		if(null == x.getChannelMask()) {
			ChannelMask cm = factory.createChannelMask();
			
			cm.setChannel11(false);
			cm.setChannel12(false);
			cm.setChannel13(false);
			cm.setChannel14(false);
			cm.setChannel15(true);
			cm.setChannel16(false);
			cm.setChannel17(false);
			cm.setChannel18(false);
			cm.setChannel19(false);
			cm.setChannel20(false);
			cm.setChannel21(false);
			cm.setChannel22(false);
			cm.setChannel23(false);
			cm.setChannel24(false);
			cm.setChannel25(false);
			cm.setChannel26(false);
			
			x.setChannelMask(cm);			
		}
		
		if(x.getEndpoints().isEmpty()) {
			Profile p = null;
			EndPoint e = factory.createEndPoint();
			e.setId(0);
			e.setName("ZDO");
							
			if (null != zwn) {
			
				for (Iterator<Profile> iterator = zwn.getProfiles().iterator(); iterator.hasNext();) {
					p = iterator.next();
					
					if (0 == p.getName().compareTo("ZDP")) {
						e.setProfile(p);
						break;
					}
				}
			}			

			/* http://trac/Zigbee-PRO/ticket/483
			 * add the endpoint first so that the check for adding the apdu succeeds */
			x.getEndpoints().add(e);

			addInputCluster(factory, a, e, p, "NWK_addr_req");
			addInputCluster(factory, a, e, p, "IEEE_addr_req");
			addInputCluster(factory, a, e, p, "Node_Desc_req");
			addInputCluster(factory, a, e, p, "Power_Desc_req");
			addInputCluster(factory, a, e, p, "Simple_Desc_req");
			addInputCluster(factory, a, e, p, "Active_EP_req");
			addInputCluster(factory, a, e, p, "Match_Desc_req");
			addInputCluster(factory, a, e, p, "Complex_Desc_req");
			addInputCluster(factory, a, e, p, "User_Desc_req");
			addInputCluster(factory, a, e, p, "Discovery_Cache_req");
			addInputCluster(factory, a, e, p, "Device_annce");
			addInputCluster(factory, a, e, p, "User_Desc_set");
			addInputCluster(factory, a, e, p, "System_Server_Discovery_req");
			addInputCluster(factory, a, e, p, "Discovery_store_req");
			addInputCluster(factory, a, e, p, "Node_Desc_store_req");
			addInputCluster(factory, a, e, p, "Power_Desc_store_req");
			addInputCluster(factory, a, e, p, "Active_EP_store_req");
			addInputCluster(factory, a, e, p, "Simple_Desc_store_req");
			addInputCluster(factory, a, e, p, "Remove_node_cache_req");
			addInputCluster(factory, a, e, p, "Find_node_chache_req");
			addInputCluster(factory, a, e, p, "Extended_Simple_Desc_req");
			addInputCluster(factory, a, e, p, "Extended_Active_EP_req");
			addInputCluster(factory, a, e, p, "End_Device_Bind_req");
			addInputCluster(factory, a, e, p, "Bind_req");
			addInputCluster(factory, a, e, p, "Unbind_req");
			addInputCluster(factory, a, e, p, "Bind_Register_req");
			addInputCluster(factory, a, e, p, "Replace_Device_req");
			addInputCluster(factory, a, e, p, "Store_Bkup_Bind_Entry_req");
			addInputCluster(factory, a, e, p, "Remove_Bkup_Bind_Entry_req");
			addInputCluster(factory, a, e, p, "Backup_Bind_Table_req");
			addInputCluster(factory, a, e, p, "Recover_Bind_Table_req");
			addInputCluster(factory, a, e, p, "Backup_Source_Bind_req");
			addInputCluster(factory, a, e, p, "Recover_Source_Bind_req");
			addInputCluster(factory, a, e, p, "Mgmt_NWK_Disc_req");
			addInputCluster(factory, a, e, p, "Mgmt_Lqi_req");
			addInputCluster(factory, a, e, p, "Mgmt_Rtg_req");
			addInputCluster(factory, a, e, p, "Mgmt_Bind_req");
			addInputCluster(factory, a, e, p, "Mgmt_Leave_req");
			addInputCluster(factory, a, e, p, "Mgmt_Direct_Join_req");
			addInputCluster(factory, a, e, p, "Mgmt_Permit_Joining_req");
			addInputCluster(factory, a, e, p, "Mgmt_Cache_req");
			addInputCluster(factory, a, e, p, "Mgmt_NWK_Update_req");
			addInputCluster(factory, a, e, p, "NWK_addr_rsp");
			addInputCluster(factory, a, e, p, "IEEE_addr_rsp");
			addInputCluster(factory, a, e, p, "Node_Desc_rsp");
			addInputCluster(factory, a, e, p, "Power_Desc_rsp");
			addInputCluster(factory, a, e, p, "Simple_Desc_rsp");
			addInputCluster(factory, a, e, p, "Active_EP_rsp");
			addInputCluster(factory, a, e, p, "Match_Desc_rsp");
			addInputCluster(factory, a, e, p, "Complex_Desc_rsp");
			addInputCluster(factory, a, e, p, "User_Desc_rsp");
			addInputCluster(factory, a, e, p, "Discovery_Cache_rsp");
			addInputCluster(factory, a, e, p, "User_Desc_conf");
			addInputCluster(factory, a, e, p, "System_Server_Discovery_rsp");
			addInputCluster(factory, a, e, p, "Discovery_store_rsp");
			addInputCluster(factory, a, e, p, "Node_Desc_store_rsp");
			addInputCluster(factory, a, e, p, "Power_Desc_store_rsp");
			addInputCluster(factory, a, e, p, "Active_EP_store_rsp");
			addInputCluster(factory, a, e, p, "Simple_Desc_store_rsp");
			addInputCluster(factory, a, e, p, "Remove_node_cache_rsp");
			addInputCluster(factory, a, e, p, "Find_node_chache_rsp");
			addInputCluster(factory, a, e, p, "Extended_Simple_Desc_rsp");
			addInputCluster(factory, a, e, p, "Extended_Active_EP_rsp");
			addInputCluster(factory, a, e, p, "End_Device_Bind_rsp");
			addInputCluster(factory, a, e, p, "Bind_rsp");
			addInputCluster(factory, a, e, p, "Unbind_rsp");
			addInputCluster(factory, a, e, p, "Bind_Register_rsp");
			addInputCluster(factory, a, e, p, "Replace_Device_rsp");
			addInputCluster(factory, a, e, p, "Store_Bkup_Bind_Entry_rsp");
			addInputCluster(factory, a, e, p, "Remove_Bkup_Bind_Entry_rsp");
			addInputCluster(factory, a, e, p, "Backup_Bind_Table_rsp");
			addInputCluster(factory, a, e, p, "Recover_Bind_Table_rsp");
			addInputCluster(factory, a, e, p, "Backup_Source_Bind_rsp");
			addInputCluster(factory, a, e, p, "Recover_Source_Bind_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_NWK_Disc_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Lqi_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Rtg_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Bind_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Leave_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Direct_Join_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Permit_Joining_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_Cache_rsp");
			addInputCluster(factory, a, e, p, "Mgmt_NWK_Update_rsp");

			addOutputCluster(factory, a, e, p, "NWK_addr_req");
			addOutputCluster(factory, a, e, p, "IEEE_addr_req");
			addOutputCluster(factory, a, e, p, "Node_Desc_req");
			addOutputCluster(factory, a, e, p, "Power_Desc_req");
			addOutputCluster(factory, a, e, p, "Simple_Desc_req");
			addOutputCluster(factory, a, e, p, "Active_EP_req");
			addOutputCluster(factory, a, e, p, "Match_Desc_req");
			addOutputCluster(factory, a, e, p, "Complex_Desc_req");
			addOutputCluster(factory, a, e, p, "User_Desc_req");
			addOutputCluster(factory, a, e, p, "Discovery_Cache_req");
			addOutputCluster(factory, a, e, p, "Device_annce");
			addOutputCluster(factory, a, e, p, "User_Desc_set");
			addOutputCluster(factory, a, e, p, "System_Server_Discovery_req");
			addOutputCluster(factory, a, e, p, "Discovery_store_req");
			addOutputCluster(factory, a, e, p, "Node_Desc_store_req");
			addOutputCluster(factory, a, e, p, "Power_Desc_store_req");
			addOutputCluster(factory, a, e, p, "Active_EP_store_req");
			addOutputCluster(factory, a, e, p, "Simple_Desc_store_req");
			addOutputCluster(factory, a, e, p, "Remove_node_cache_req");
			addOutputCluster(factory, a, e, p, "Find_node_chache_req");
			addOutputCluster(factory, a, e, p, "Extended_Simple_Desc_req");
			addOutputCluster(factory, a, e, p, "Extended_Active_EP_req");
			addOutputCluster(factory, a, e, p, "End_Device_Bind_req");
			addOutputCluster(factory, a, e, p, "Bind_req");
			addOutputCluster(factory, a, e, p, "Unbind_req");
			addOutputCluster(factory, a, e, p, "Bind_Register_req");
			addOutputCluster(factory, a, e, p, "Replace_Device_req");
			addOutputCluster(factory, a, e, p, "Store_Bkup_Bind_Entry_req");
			addOutputCluster(factory, a, e, p, "Remove_Bkup_Bind_Entry_req");
			addOutputCluster(factory, a, e, p, "Backup_Bind_Table_req");
			addOutputCluster(factory, a, e, p, "Recover_Bind_Table_req");
			addOutputCluster(factory, a, e, p, "Backup_Source_Bind_req");
			addOutputCluster(factory, a, e, p, "Recover_Source_Bind_req");
			addOutputCluster(factory, a, e, p, "Mgmt_NWK_Disc_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Lqi_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Rtg_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Bind_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Leave_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Direct_Join_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Permit_Joining_req");
			addOutputCluster(factory, a, e, p, "Mgmt_Cache_req");
			addOutputCluster(factory, a, e, p, "Mgmt_NWK_Update_req");
			addOutputCluster(factory, a, e, p, "NWK_addr_rsp");
			addOutputCluster(factory, a, e, p, "IEEE_addr_rsp");
			addOutputCluster(factory, a, e, p, "Node_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Power_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Simple_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Active_EP_rsp");
			addOutputCluster(factory, a, e, p, "Match_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Complex_Desc_rsp");
			addOutputCluster(factory, a, e, p, "User_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Discovery_Cache_rsp");
			addOutputCluster(factory, a, e, p, "User_Desc_conf");
			addOutputCluster(factory, a, e, p, "System_Server_Discovery_rsp");
			addOutputCluster(factory, a, e, p, "Discovery_store_rsp");
			addOutputCluster(factory, a, e, p, "Node_Desc_store_rsp");
			addOutputCluster(factory, a, e, p, "Power_Desc_store_rsp");
			addOutputCluster(factory, a, e, p, "Active_EP_store_rsp");
			addOutputCluster(factory, a, e, p, "Simple_Desc_store_rsp");
			addOutputCluster(factory, a, e, p, "Remove_node_cache_rsp");
			addOutputCluster(factory, a, e, p, "Find_node_chache_rsp");
			addOutputCluster(factory, a, e, p, "Extended_Simple_Desc_rsp");
			addOutputCluster(factory, a, e, p, "Extended_Active_EP_rsp");
			addOutputCluster(factory, a, e, p, "End_Device_Bind_rsp");
			addOutputCluster(factory, a, e, p, "Bind_rsp");
			addOutputCluster(factory, a, e, p, "Unbind_rsp");
			addOutputCluster(factory, a, e, p, "Bind_Register_rsp");
			addOutputCluster(factory, a, e, p, "Replace_Device_rsp");
			addOutputCluster(factory, a, e, p, "Store_Bkup_Bind_Entry_rsp");
			addOutputCluster(factory, a, e, p, "Remove_Bkup_Bind_Entry_rsp");
			addOutputCluster(factory, a, e, p, "Backup_Bind_Table_rsp");
			addOutputCluster(factory, a, e, p, "Recover_Bind_Table_rsp");
			addOutputCluster(factory, a, e, p, "Backup_Source_Bind_rsp");
			addOutputCluster(factory, a, e, p, "Recover_Source_Bind_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_NWK_Disc_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Lqi_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Rtg_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Bind_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Leave_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Direct_Join_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Permit_Joining_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_Cache_rsp");
			addOutputCluster(factory, a, e, p, "Mgmt_NWK_Update_rsp");
			
		}
		
		/* add a binding table */
		BindingTable bt = factory.createBindingTable();
		bt.setSize(16);
		x.setBindingTable(bt);
		
		/* set node defaults from ZWN defaults */
		
		// default apsUseExtPANId to ZWN value 
		x.setApsUseExtPANId(zwn.getDefaultExtendedPANId());
		x.setSecurityEnabled(zwn.isDefaultSecurityEnabled());
		
		// Nib values based on network size
//		x.setAddressMapTableSize(BigInteger.valueOf(maxNumNodes));
//		x.setActiveNeighbourTableSize(BigInteger.valueOf(maxNumNodes));		
	}

	private void addInputCluster(ZPSConfigurationFactory factory, APDU a, EndPoint e, Profile p, String clusterName) {
		
		if (null == a || null == p || null == e) {
			return;
		}
		
		InputCluster ic = factory.createInputCluster();
		
		ic.setEndPoint(e);
		ic.setRxAPDU(a);
		ic.setDiscoverable(false);
		
		for (Iterator<Cluster> iterator = p.getClusters().iterator(); iterator.hasNext();) {
			Cluster cluster = (Cluster) iterator.next();
			
			if (0 == cluster.getName().compareTo(clusterName)) {
				ic.setCluster(cluster);
				break;
			}
		}
		
		e.getInputClusters().add(ic);
	}
	
	private void addOutputCluster(ZPSConfigurationFactory factory, APDU a, EndPoint e, Profile p, String clusterName) {
		
		if (null == a || null == p || null == e) {
			return;
		}
		
		OutputCluster oc = factory.createOutputCluster();
		
		oc.setEndPoint(e);
		oc.getTxAPDUs().add(a);
		oc.setDiscoverable(false);
		for (Iterator<Cluster> iterator = p.getClusters().iterator(); iterator.hasNext();) {
			Cluster cluster = (Cluster) iterator.next();
			
			if (0 == cluster.getName().compareTo(clusterName)) {
				oc.setCluster(cluster);
				break;
			}
		}
		
		e.getOutputClusters().add(oc);
	}

	private void enrichCoordinator(ZPSConfigurationFactory factory, Coordinator x) {
		
		x.setName("Coordinator");
		
		if(zwn.isDefaultSecurityEnabled() && x.getTrustCenter() == null) {
			TrustCenter tc = factory.createTrustCenter();
			
			tc.setDeviceTableSize(zwn.getMaxNumberNodes());
			
			DefaultNwkKey key = factory.createDefaultNwkKey();
			
			/* use default network key */
			tc.setKeys(key);

			x.setInitialNetworkKey(key);					

			x.setTrustCenter(tc);
		}
		
		if (x.getZDOServers() == null) {
			ZDOServersCoordinator zdoServers = factory.createZDOServersCoordinator();
			
			x.setZDOServers(zdoServers);
			
			APDU a = null;
			for (Iterator<APDU> iterator = x.getPDUConfiguration().getAPDUs().iterator(); iterator.hasNext();) {
				APDU ia = (APDU) iterator.next();
				
				if (0 == ia.getName().compareTo("apduZDP")) {
					a = ia;
					break;
				}
			}
			
			zdoServers.setDefaultServer((DefaultServer)initialiseZdoServer(factory.createDefaultServer(), a));
			zdoServers.setZdoClient((ZdoClient)initialiseZdoServer(factory.createZdoClient(), a));
			zdoServers.setDeviceAnnceServer((DeviceAnnceServer)initialiseZdoServer(factory.createDeviceAnnceServer(), a));
			zdoServers.setNwkAddrServer((NwkAddrServer)initialiseZdoServer(factory.createNwkAddrServer(), a));
			zdoServers.setIeeeAddrServer((IeeeAddrServer)initialiseZdoServer(factory.createIeeeAddrServer(), a));

			zdoServers.setPermitJoiningServer((PermitJoiningServer)initialiseZdoServer(factory.createPermitJoiningServer(), a));
			zdoServers.setSystemServerDiscoveryServer((SystemServerDiscoveryServer)initialiseZdoServer(factory.createSystemServerDiscoveryServer(), a));

			zdoServers.setNodeDescServer((NodeDescServer)initialiseZdoServer(factory.createNodeDescServer(), a));
			zdoServers.setPowerDescServer((PowerDescServer)initialiseZdoServer(factory.createPowerDescServer(), a));
			zdoServers.setSimpleDescServer((SimpleDescServer)initialiseZdoServer(factory.createSimpleDescServer(), a));
			
			zdoServers.setActiveEpServer((ActiveEpServer)initialiseZdoServer(factory.createActiveEpServer(), a));
			zdoServers.setMatchDescServer((MatchDescServer)initialiseZdoServer(factory.createMatchDescServer(), a));

			zdoServers.setMgmtLeaveServer((MgmtLeaveServer)initialiseZdoServer(factory.createMgmtLeaveServer(), a));
			zdoServers.setMgmtLqiServer((MgmtLqiServer)initialiseZdoServer(factory.createMgmtLqiServer(), a));
			zdoServers.setMgmtRtgServer((MgmtRtgServer)initialiseZdoServer(factory.createMgmtRtgServer(), a));
			zdoServers.setMgmtNWKUpdateServer((MgmtNWKUpdateServer)initialiseZdoServer(factory.createMgmtNWKUpdateServer(), a));
//			zdoServers.setMgmtBindServer((MgmtBindServer)initialiseZdoServer(factory.createMgmtBindServer(), a));

			zdoServers.setBindUnbindServer((BindUnbindServer)initialiseZdoServer(factory.createBindUnbindServer(), a));
			zdoServers.setBindRequestServer((BindRequestServer)initialiseZdoServer(factory.createBindRequestServer(), a));
			zdoServers.setEndDeviceBindServer((EndDeviceBindServer)initialiseZdoServer(factory.createEndDeviceBindServer(), a));
		}

	}

	private void enrichRouter(ZPSConfigurationFactory factory, Router x) {
		Integer newIdx = 1;		
		boolean match = false;
		String newZRName;
		
		do {
			newZRName = "Router" + newIdx.toString();
		
			newIdx += 1;
			match = false;
			
			for (Iterator<ChildNodes> iterator = zwn.getChildNodes().iterator(); iterator.hasNext();) {
				ChildNodes node = iterator.next();
				
				if (node instanceof Router) {
					if (0 == ((Router) node).getName().compareTo(newZRName)) {
						match = true;
					}
				}
			}			
		} while (match);

		x.setName(newZRName);
		
		if (x.getZDOServers() == null) {
			ZDOServersRouter zdoServers = factory.createZDOServersRouter();
			
			x.setZDOServers(zdoServers);
			
			APDU a = null;
			for (Iterator<APDU> iterator = x.getPDUConfiguration().getAPDUs().iterator(); iterator.hasNext();) {
				APDU ia = (APDU) iterator.next();
				
				if (0 == ia.getName().compareTo("apduZDP")) {
					a = ia;
					break;
				}
			}
			
			zdoServers.setDefaultServer((DefaultServer)initialiseZdoServer(factory.createDefaultServer(), a));
			zdoServers.setZdoClient((ZdoClient)initialiseZdoServer(factory.createZdoClient(), a));
			zdoServers.setDeviceAnnceServer((DeviceAnnceServer)initialiseZdoServer(factory.createDeviceAnnceServer(), a));
			zdoServers.setNwkAddrServer((NwkAddrServer)initialiseZdoServer(factory.createNwkAddrServer(), a));
			zdoServers.setIeeeAddrServer((IeeeAddrServer)initialiseZdoServer(factory.createIeeeAddrServer(), a));

			zdoServers.setPermitJoiningServer((PermitJoiningServer)initialiseZdoServer(factory.createPermitJoiningServer(), a));
			zdoServers.setSystemServerDiscoveryServer((SystemServerDiscoveryServer)initialiseZdoServer(factory.createSystemServerDiscoveryServer(), a));

			zdoServers.setNodeDescServer((NodeDescServer)initialiseZdoServer(factory.createNodeDescServer(), a));
			zdoServers.setPowerDescServer((PowerDescServer)initialiseZdoServer(factory.createPowerDescServer(), a));
			zdoServers.setSimpleDescServer((SimpleDescServer)initialiseZdoServer(factory.createSimpleDescServer(), a));
			
			zdoServers.setActiveEpServer((ActiveEpServer)initialiseZdoServer(factory.createActiveEpServer(), a));
			zdoServers.setMatchDescServer((MatchDescServer)initialiseZdoServer(factory.createMatchDescServer(), a));

			zdoServers.setMgmtLeaveServer((MgmtLeaveServer)initialiseZdoServer(factory.createMgmtLeaveServer(), a));
			zdoServers.setMgmtLqiServer((MgmtLqiServer)initialiseZdoServer(factory.createMgmtLqiServer(), a));
			zdoServers.setMgmtRtgServer((MgmtRtgServer)initialiseZdoServer(factory.createMgmtRtgServer(), a));
			zdoServers.setMgmtNWKUpdateServer((MgmtNWKUpdateServer)initialiseZdoServer(factory.createMgmtNWKUpdateServer(), a));

			zdoServers.setBindUnbindServer((BindUnbindServer)initialiseZdoServer(factory.createBindUnbindServer(), a));
			zdoServers.setBindRequestServer((BindRequestServer)initialiseZdoServer(factory.createBindRequestServer(), a));
		}

		if (zwn.isDefaultSecurityEnabled()) {
			/* find trust center */
			if (null != zwn.getCoordinator()) {
				if (null != zwn.getCoordinator().getTrustCenter()) {
					/* set initial key to default key on TC */
					x.setInitialNetworkKey(zwn.getCoordinator().getTrustCenter().getKeys());					
				}
			}
		}
		
		x.setRouteDiscoveryTableSize(BigInteger.valueOf(1));
		x.setRoutingTableSize(BigInteger.valueOf(60));
		
	}

	private void enrichEndDevice(ZPSConfigurationFactory factory, EndDevice x) {
		
		
		Integer newIdx = 1;		
		boolean match = false;
		String newZEDName;
		
		do {
			newZEDName = "EndDevice" + newIdx.toString();
		
			newIdx += 1;
			match = false;
			
			for (Iterator<ChildNodes> iterator = zwn.getChildNodes().iterator(); iterator.hasNext();) {
				ChildNodes node = iterator.next();
				
				if (node instanceof EndDevice) {
					if (0 == ((EndDevice) node).getName().compareTo(newZEDName)) {
						match = true;
					}
				}
			}			
		} while (match);
		
		x.setName(newZEDName);

		if (x.getZDOServers() == null) {
			ZDOServersEndDevice zdoServers = factory.createZDOServersEndDevice();
			
			x.setZDOServers(zdoServers);
			
			APDU a = null;
			for (Iterator<APDU> iterator = x.getPDUConfiguration().getAPDUs().iterator(); iterator.hasNext();) {
				APDU ia = (APDU) iterator.next();
				
				if (0 == ia.getName().compareTo("apduZDP")) {
					a = ia;
					break;
				}
			}
			
			zdoServers.setDefaultServer((DefaultServer)initialiseZdoServer(factory.createDefaultServer(), a));
			zdoServers.setZdoClient((ZdoClient)initialiseZdoServer(factory.createZdoClient(), a));
			zdoServers.setDeviceAnnceServer((DeviceAnnceServer)initialiseZdoServer(factory.createDeviceAnnceServer(), a));
			zdoServers.setNwkAddrServer((NwkAddrServer)initialiseZdoServer(factory.createNwkAddrServer(), a));
			zdoServers.setIeeeAddrServer((IeeeAddrServer)initialiseZdoServer(factory.createIeeeAddrServer(), a));

			zdoServers.setSystemServerDiscoveryServer((SystemServerDiscoveryServer)initialiseZdoServer(factory.createSystemServerDiscoveryServer(), a));

			zdoServers.setNodeDescServer((NodeDescServer)initialiseZdoServer(factory.createNodeDescServer(), a));
			zdoServers.setPowerDescServer((PowerDescServer)initialiseZdoServer(factory.createPowerDescServer(), a));
			zdoServers.setSimpleDescServer((SimpleDescServer)initialiseZdoServer(factory.createSimpleDescServer(), a));
			
			zdoServers.setActiveEpServer((ActiveEpServer)initialiseZdoServer(factory.createActiveEpServer(), a));
			zdoServers.setMatchDescServer((MatchDescServer)initialiseZdoServer(factory.createMatchDescServer(), a));

			zdoServers.setMgmtLeaveServer((MgmtLeaveServer)initialiseZdoServer(factory.createMgmtLeaveServer(), a));
			zdoServers.setMgmtLqiServer((MgmtLqiServer)initialiseZdoServer(factory.createMgmtLqiServer(), a));
			zdoServers.setMgmtNWKUpdateServer((MgmtNWKUpdateServer)initialiseZdoServer(factory.createMgmtNWKUpdateServer(), a));

			zdoServers.setBindUnbindServer((BindUnbindServer)initialiseZdoServer(factory.createBindUnbindServer(), a));
			zdoServers.setBindRequestServer((BindRequestServer)initialiseZdoServer(factory.createBindRequestServer(), a));
		}

		if (zwn.isDefaultSecurityEnabled()) {
			/* find trust center */
			if (null != zwn.getCoordinator()) {
				if (null != zwn.getCoordinator().getTrustCenter()) {
					/* set initial key to default key on TC */
					x.setInitialNetworkKey(zwn.getCoordinator().getTrustCenter().getKeys());					
				}
			}
		}
		
		// End devices only have one neighbour which is their parent
		x.setActiveNeighbourTableSize(BigInteger.valueOf(1));
		x.setRoutingTableSize(BigInteger.valueOf(1));
	}
	
	private ZDOClientServer initialiseZdoServer(ZDOClientServer server, APDU a) {
		server.setOutputAPdu(a);
		
		return server;
	}
}






