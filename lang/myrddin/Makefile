# $OpenBSD: Makefile,v 1.6 2017/11/06 17:10:18 bcallah Exp $

ONLY_FOR_ARCHS =	amd64

COMMENT =		systems language that is both powerful and fun to use

DISTNAME =		myrddin-0.2.0
REVISION =		0
CATEGORIES =		lang

MAINTAINER =		James Turner <james@calminferno.net>

HOMEPAGE =		https://myrlang.org/
MASTER_SITES =		https://myrlang.org/releases/

# MIT
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB	+= c

WRKDIST =		${WRKDIR}/mc

CONFIGURE_STYLE =	simple
USE_GMAKE =		Yes

TEST_TARGET =		check

# Remove hardcoded optimizations.
pre-configure:
	sed -i -e 's,-Werror,,g' -e 's,-O0,,g' ${WRKSRC}/mk/c.mk

.include <bsd.port.mk>
