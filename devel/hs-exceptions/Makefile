# $OpenBSD: Makefile,v 1.5 2017/11/07 22:11:08 kili Exp $

COMMENT =		extensible optionally-pure exceptions

DISTNAME =		exceptions-0.8.3
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	7py7fmRxowDFpHmiHGKrTb

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS +=		devel/hs-mtl>=2.0,<2.3 \
			devel/hs-stm>=2.2,<3 \
    			devel/hs-transformers-compat>=0.3,<0.6

.include <bsd.port.mk>
