# $OpenBSD: Makefile,v 1.11 2017/11/08 18:56:11 kili Exp $

COMMENT =		HUnit support for hs-test-framework

DISTNAME =		test-framework-hunit-0.3.0.2
REVISION =		1
CATEGORIES =		devel

HOMEPAGE =		http://batterseapower.github.com/test-framework/

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	1359hgLIftd5Xd2lJUqc06

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-extensible-exceptions>=0.1.1,<0.2.0 \
			devel/hs-test-framework>=0.2.0 \
			devel/hs-HUnit>=1.2,<1.4

.include <bsd.port.mk>
