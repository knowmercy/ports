# $OpenBSD: Makefile,v 1.5 2015/06/19 14:09:20 jasper Exp $

COMMENT=		UUID generator

DISTNAME=		uuid-2.3.8
CATEGORIES=		devel

HOMEPAGE=		https://github.com/assaf/uuid

# MIT
PERMIT_PACKAGE_CDROM=	Yes

MODULES=		lang/ruby

CONFIGURE_STYLE=	gem

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		net/ruby-macaddr,${MODRUBY_FLAVOR}

MODRUBY_TEST=		rake

.include <bsd.port.mk>
