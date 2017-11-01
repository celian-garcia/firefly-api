FROM celiangarcia/gcc7-cmake:3.9.0

ENV TERM xterm-256color

# Add the PostgreSQL PGP key to verify their Debian packages.
# It should be the same key as https://www.postgresql.org/media/keys/ACCC4CF8.asc
RUN apt-key adv --keyserver hkp://wwwkeys.pgp.net --recv-keys B97B0AFCAA1A47F044F244A07FCC7D46ACCC4CF8

# Add PostgreSQL's repository. It contains the most recent stable release
RUN echo "deb http://apt.postgresql.org/pub/repos/apt/ precise-pgdg main" > /etc/apt/sources.list.d/pgdg.list
RUN apt-get update \
 && DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential wget libbz2-dev \
 && apt-get install -y vim libopencv-dev libcv-dev software-properties-common libpq-dev postgresql-9.6 \
 postgresql-client-9.6 postgresql-contrib-9.6 net-tools

# Boost installation (inspired from lballabio docker file https://github.com/lballabio/dockerfiles/blob/master/boost/Dockerfile)
ARG boost_version=1.64.0
ARG boost_dir=boost_1_64_0
ENV boost_version ${boost_version}

RUN wget https://dl.bintray.com/boostorg/release/${boost_version}/source/${boost_dir}.tar.gz \
    && tar xfz ${boost_dir}.tar.gz \
    && rm ${boost_dir}.tar.gz \
    && cd ${boost_dir} \
    && ./bootstrap.sh \
    && ./b2 --without-python --prefix=/usr -j 4 link=shared runtime-link=shared install \
    && cd .. && rm -rf ${boost_dir} && ldconfig

# Google test installation
RUN apt-get install -y libgtest-dev \
    && cd /usr/src/gtest \
    && mkdir build && cd build \
    && cmake .. \
    && make -j 12 \
    && make install

WORKDIR /firefly
COPY . .

RUN rm -rf build \
    && mkdir build \
    && cd build \
    && ls -l \
    && cmake -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql .. \
    && make -j 12 \
