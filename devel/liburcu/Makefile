# $OpenBSD: Makefile,v 1.11 2017/11/02 12:46:44 jca Exp $

BROKEN-hppa =		undefined reference to __sync atomic ops

COMMENT =		user-level RCU implementation

GH_ACCOUNT =		urcu
GH_PROJECT =		userspace-rcu
GH_TAGNAME =		v0.8.9
DISTNAME =		liburcu-${GH_TAGNAME:S/^v//}

SHARED_LIBS +=  urcu-bp                   0.0 # 2.0
SHARED_LIBS +=  urcu-cds                  0.0 # 2.0
SHARED_LIBS +=  urcu-common               0.0 # 2.0
SHARED_LIBS +=  urcu-mb                   0.0 # 2.0
SHARED_LIBS +=  urcu-qsbr                 0.0 # 2.0
SHARED_LIBS +=  urcu-signal               0.0 # 2.0
SHARED_LIBS +=  urcu                      0.0 # 2.0

CATEGORIES =		devel

HOMEPAGE =		http://liburcu.org/

MAINTAINER = 		Jeremie Courreges-Anglas <jca@wxcvbn.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		pthread

# For atomic builtins
MODULES+=		gcc4
MODGCC4_ARCHS=		alpha arm
.if ${MACHINE_ARCH} == "alpha"
MODGCC4_VERSION=	4.6
.endif
# Thread-local storage emulation from clang or lang/gcc doesn't work in
# regress tests.
CONFIGURE_ENV =		ac_cv_tls=none

BUILD_DEPENDS =		${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool,-main

USE_GMAKE =		Yes

CONFIGURE_STYLE =	gnu

AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.11

pre-configure:
	cd ${WRKSRC} && env ${MAKE_ENV} \
	    AUTOCONF_VERSION=${AUTOCONF_VERSION} \
	    AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
	    autoreconf -vif

.include <bsd.port.mk>
