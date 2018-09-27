FROM celiangarcia/firefly-api-base:0.4

WORKDIR /usr/src/firefly
COPY . .
COPY resources /srv/firefly/www

RUN rm -rf build \
    && mkdir build \
    && cd build \
    && cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql .. \
    && make -j 12 \
    && make install
