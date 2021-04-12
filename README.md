# Hometec

## Create Environment

git clone -b zero https://github.com/sjgarani/hometec.git hometec
cd hometec
export HWS=$(pwd)
git submodule update --init --recursive

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

rm conf/local.conf conf/bblayers.conf
ln -s $HWS/conf/local.conf $HWS/poky/build/conf/local.conf
ln -s $HWS/conf/bblayers.conf $HWS/poky/build/conf/lobblayerscal.conf

## Generate Raspberry Pi 3 image

cd poky/
source oe-init-build-env
bitbake core-image-base

## Run in Docker

### From Yocto image


### Article

https://infoembedded.com/blog/how-to-build-custom-linux-using-yocto-for-raspberry-pi/
https://jacobncalvert.com/2019/12/22/building-a-customized-linux-image-for-raspberry-pi-with-yocto-docker-support/

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