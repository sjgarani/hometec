SUMMARY = "State Machine of Hometec"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS += "curl openssl crossguid jansson libffi libxml2"

SRCREV = "${AUTOREV}"

SRC_URI = "git://github.com/apache/celix.git;branch=master;protocol=https"

S = "${WORKDIR}/git"

inherit pkgconfig cmake

EXTRA_OECMAKE = ""
