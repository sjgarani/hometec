SUMMARY = "Maintec"
SECTION = "celix"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS += "cacao curl openssl jansson libffi libxml2 zeromq czmq"

SRC_URI = "git://github.com/apache/celix.git;protocol=https;tag=rel/celix-${PV} \
           file://0001-Update-to-Cross-Compile-in-Yocto.patch \
           file://0002-Update-to-Generate-Shared-Library-Version.patch"

S = "${WORKDIR}/git"

inherit pkgconfig cmake

EXTRA_OECMAKE = "-DBUILD_LAUNCHER=OFF -DBUILD_REMOTE_SERVICE_ADMIN=ON -DBUILD_RSA_DISCOVERY_CONFIGURED=ON -DBUILD_RSA_REMOTE_SERVICE_ADMIN_HTTP=ON -DBUILD_RSA_REMOTE_SERVICE_ADMIN_DFI=ON -DBUILD_LOG_SERVICE=ON"

INSANE_SKIP_${PN} += "useless-rpaths"