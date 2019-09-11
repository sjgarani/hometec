SUMMARY = "Simple Hello World Cmake application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS += "boost"

SRC_URI = "\
            file://CMakeLists.txt \
            file://main.cpp \
        "

S = "${WORKDIR}"

inherit pkgconfig cmake

EXTRA_OECMAKE = ""

do_install() {
    install -d ${D}${bindir}
    install -m 0755 statemachine ${D}${bindir}
}