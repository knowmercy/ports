# $OpenBSD: Makefile,v 1.26 2017/11/09 16:50:39 ajacoutot Exp $

COMMENT =		open source message queue optimised for performance

DISTNAME =		zeromq-4.1.4
REVISION =		1

SHARED_LIBS +=  zmq                  4.1      # 5.0

CATEGORIES =		net
HOMEPAGE =		http://zeromq.org/

MAINTAINER =		Rodrigo Mosconi <openbsd@mosconi.mat.br>

# LGPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c m pthread sodium ${COMPILER_LIBCXX}

MASTER_SITES =		http://download.zeromq.org/

LIB_DEPENDS =		security/libsodium

USE_GMAKE =		Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--with-libsodium=${LOCALBASE}

# XXX libsodium: https://github.com/jedisct1/libsodium/pull/104
CONFIGURE_ENV =		CXXFLAGS="-Wno-long-long ${CXXFLAGS}"

# test_system needs to be able to create at least 496 sockets
do-test:
	cd ${WRKSRC} && ulimit -n 1024 && ${MAKE_PROGRAM} ${TEST_TARGET}

.include <bsd.port.mk>
