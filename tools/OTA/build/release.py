#
# Copyright 2023 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

import os
import platform
import PyInstaller.__main__
import git

VERSION_FILE_NAME = 'version.txt'

script_path = os.path.dirname(os.path.abspath(__file__))

# Get SCRIPT DIRECTORY, used for local referenced files (SB3 jsons, keys & certs)
SCRIPT_DIRECTORY = os.path.abspath(os.path.realpath(script_path))

NXPZBOTA_DIRECTORY = os.path.join(SCRIPT_DIRECTORY, '..')
VERSION_FILE_PATH = os.path.abspath(os.path.realpath(os.path.join(NXPZBOTA_DIRECTORY, VERSION_FILE_NAME)))

if __name__ == '__main__':
    # Deletes current version.txt file
    if os.path.exists(VERSION_FILE_PATH):
        print(f'Found version.txt: {VERSION_FILE_PATH}, to delete')
        os.remove(VERSION_FILE_PATH)

    # Writes latest git version info to 'version.txt'
    r = git.repo.Repo(search_parent_directories=True)
    version_info = r.git.rev_parse(r.head, short=True)
    print(f'Writing version.txt: {VERSION_FILE_PATH} with {version_info}')
    with open(VERSION_FILE_PATH, 'w') as f:
        f.write(version_info)
        f.write('\n')
        f.close()

    if platform.system() == 'Windows':
        print('Generating EXE')
        print('In order to generate EXE, a virtualenv named "nxpzbota" is is required and needed dependencies should be installed')
            # Builds production version (no debug console window)
        PyInstaller.__main__.run([
            os.path.join(SCRIPT_DIRECTORY, 'nxpzbota.spec')
        ])

        print('Exe should be in dist folder.')
