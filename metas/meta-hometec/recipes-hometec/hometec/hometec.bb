SUMMARY = "State Machine of Hometec"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# DEPENDS += "boost"

SRCREV = "${AUTOREV}"

SRC_URI = "git://github.com/sjgarani/hometec.git;branch=master;protocol=git"

S = "${WORKDIR}/git"

inherit pkgconfig cmake

EXTRA_OECMAKE = ""

do_install() {
    install -d ${D}${libexecdir}
    # install -m 0755 hometec ${D}${libexecdir}
    install -m 0755 deploy/hometec/hometec ${D}${libexecdir}
}