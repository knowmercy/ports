# $OpenBSD: Makefile,v 1.23 2017/11/07 21:29:08 kili Exp $

COMMENT =		efficient packed Unicode text type

# Dependency of meta/haskell-platform.
# Please do *not* update without thinking.
PORTROACH =		ignore:1

DISTNAME =		text-1.2.1.3
REVISION =		2
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	K7urvJEq0WALu3FXMx2wrP

.include <bsd.port.mk>
