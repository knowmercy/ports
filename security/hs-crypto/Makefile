# $OpenBSD: Makefile,v 1.24 2017/11/07 22:37:56 kili Exp $

COMMENT =	Haskell cryptographic library
CATEGORIES =	security

V =		4.2.5.1
DISTNAME =	Crypto-$V
REVISION =	4
# Historically named with a lower case `c'.
PKGNAME =	hs-crypto-$V

MAINTAINER =	Matthias Kilian <kili@openbsd.org>

# 3 different licenses from 3 authors: BSD, GPL, BSD-ish
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	4FPC699EKbJE1prYVMCV9E

RUN_DEPENDS =		devel/hs-HUnit \
			devel/hs-QuickCheck>=2.4.0.1 \
			devel/hs-random
BUILD_DEPENDS =		${RUN_DEPENDS}

do-test:
.for t in HMACTest QuickTest RSATest SHA1Test SymmetricTest WordListTest
	cd ${WRKBUILD} && ./dist/build/$t/$t
.endfor

.include <bsd.port.mk>
