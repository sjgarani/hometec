FROM celix/base

RUN git clone https://github.com/sjgarani/lightec.git && \
    cd lightec && \
    git submodule update --init bundles/lightec_api && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make

EXPOSE 6666
EXPOSE 9999
EXPOSE 18888
