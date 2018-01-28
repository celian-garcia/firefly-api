FROM celiangarcia/firefly-server:0.5

WORKDIR /firefly
COPY . .

RUN pkg-config --version

RUN rm -rf build \
    && mkdir build \
    && cd build \
    && ls -l \
    && cmake -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql .. \
    && make -j 12 \
