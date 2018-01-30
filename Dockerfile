FROM celiangarcia/firefly-api-base:0.1

WORKDIR /firefly
COPY . .

RUN rm -rf build \
    && mkdir build \
    && cd build \
    && ls -l \
    && cmake -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql .. \
    && make -j 12 \
