# $OpenBSD: Makefile,v 1.30 2017/11/07 21:59:36 kili Exp $

COMMENT =		parser and writer for config files

DISTNAME =		ConfigFile-1.1.4
REVISION =		7
CATEGORIES =		devel sysutils
HOMEPAGE =		https://github.com/jgoerzen/configfile/wiki

MAINTAINER =		David Coppa <dcoppa@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	7CzxnBOMDE5COFEXwnYW9

RUN_DEPENDS +=		devel/hs-MissingH>=1.0.0 \
			devel/hs-mtl
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
