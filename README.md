# Hometec

## Create Environment

git submodule add -b dunfell git://git.yoctoproject.org/poky poky
git submodule add -b dunfell git://git.yoctoproject.org/meta-raspberrypi metas/meta-raspberrypi
git submodule add -b dunfell git://git.yoctoproject.org/meta-java metas/meta-java
git submodule add -b dunfell git://git.openembedded.org/meta-openembedded metas/meta-openembedded

cd poky/
./scripts/install-buildtools
source buildtools/environment-setup-x86_64-pokysdk-linux
source oe-init-build-env

bitbake-layers add-layer ../../metas/meta-raspberrypi/
bitbake-layers add-layer ../../metas/meta-java/
bitbake-layers add-layer ../../metas/meta-openembedded/meta-oe/

Edit conf/local.conf, add MACHINE ?= "raspberrypi3".

## Generate Raspberry Pi 3 image

### Article

https://infoembedded.com/blog/how-to-build-custom-linux-using-yocto-for-raspberry-pi/

###### Old:
Install

Artigo:
    https://www.embarcados.com.br/linux-para-a-raspberry-pi-3-usando-yocto/
    https://github.com/jirihnidek/daemon

Git:
    git clone -b thud http://git.yoctoproject.org/git/poky yocto
    git clone -b thud git://git.openembedded.org/meta-openembedded yocto/meta-openembedded
    git clone -b angstrom-v2018.12-thud git://github.com/Angstrom-distribution/meta-angstrom.git yocto/meta-angstrom
    git clone -b thud git://git.yoctoproject.org/meta-raspberrypi yocto/meta-raspberrypi
    git clone -b thud https://github.com/meta-qt5/meta-qt5.git yocto/meta-qt5

Create Layer:
    cd $WORKSPACE
    bitbake-layers create-layer meta-hometec
    bitbake-layers add-layer /workspaces/hometec/meta-hometec

Yocto:
    source oe-init-build-env
    bitbake core-image-base