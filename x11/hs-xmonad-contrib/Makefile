# $OpenBSD: Makefile,v 1.32 2017/11/07 22:44:27 kili Exp $

COMMENT =		third party xmonad extensions

DISTNAME =		xmonad-contrib-0.12
CATEGORIES =		x11
HOMEPAGE =		http://www.xmonad.org/

MAINTAINER =		Jona Joachim <jona@joachim.cc>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage register haddock

MODGHC_PACKAGE_KEY =	1H4hVz6Iw07CCz77gLFtS1

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-extensible-exceptions \
			devel/hs-mtl>=1,<3 \
			devel/hs-old-locale \
			devel/hs-old-time \
			devel/hs-random \
			devel/hs-utf8-string \
			shells/bash \
			x11/hs-X11>=1.6.1,<1.7 \
			x11/hs-X11-xft>=0.2 \
			x11/xmonad,-lib>=0.12,<0.13

NO_TEST =		Yes

.include <bsd.port.mk>
