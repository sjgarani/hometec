SUMMARY = "Maintec"
SECTION = "celix"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS += "boost cacao curl openssl jansson libffi libxml2 zeromq czmq"

SRCREV = "${AUTOREV}"

SRC_URI = "git://github.com/apache/celix.git;branch=master;protocol=git \
           file://0001-Remove-Werror-flag.patch \
           file://0002-Update-to-Generate-Shared-Library-Version.patch"

S = "${WORKDIR}/git"

inherit pkgconfig cmake

EXTRA_OECMAKE = "-DBUILD_LAUNCHER=OFF -DBUILD_REMOTE_SERVICE_ADMIN=ON -DBUILD_RSA_REMOTE_SERVICE_ADMIN_DFI=ON"

INSANE_SKIP_${PN} += "useless-rpaths installed-vs-shipped"
