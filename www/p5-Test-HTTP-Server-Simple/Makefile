# $OpenBSD: Makefile,v 1.9 2016/03/20 19:57:22 naddy Exp $

COMMENT= 	test framework for HTTP::Server::Simple

MODULES=	cpan
PKG_ARCH=	*

DISTNAME =	Test-HTTP-Server-Simple-0.11
CATEGORIES=	www devel

# perl
PERMIT_PACKAGE_CDROM=	Yes

RUN_DEPENDS=	www/p5-HTTP-Server-Simple
MAKE_ENV=	TEST_POD=Yes

.include <bsd.port.mk>
