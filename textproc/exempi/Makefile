# $OpenBSD: Makefile,v 1.15 2017/07/26 22:45:30 sthen Exp $

# g++3 chokes on the code
NOT_FOR_ARCHS=	${GCC3_ARCHS}

COMMENT =		implementation of XMP
DISTNAME =		exempi-2.2.1
REVISION =		1

CATEGORIES =		textproc

SHARED_LIBS +=  exempi               1.1      # 5.3

HOMEPAGE =		http://libopenraw.freedesktop.org/wiki/Exempi

# BSD
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c expat m pthread ${COMPILER_LIBCXX} z

# configure checks for libiconv but it's unused
BUILD_DEPENDS =		converters/libiconv

MASTER_SITES =		http://libopenraw.freedesktop.org/download/

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--enable-unittest=no
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -pthread"

# XXX remove when we have thread local storage
CONFIGURE_ENV +=	ac_cv_tls=none

.include <bsd.port.mk>
