# $OpenBSD: Makefile,v 1.5 2017/11/05 17:07:01 ajacoutot Exp $

COMMENT =		best practices checker for ansible

MODPY_EGG_VERSION =	3.4.17
DISTNAME =		ansible-lint-${MODPY_EGG_VERSION}

CATEGORIES =		sysutils

# BSD
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
MODPY_PI =		Yes

RUN_DEPENDS =		sysutils/ansible
PORTHOME =		${WRKDIR}

TEST_DEPENDS =		sysutils/ansible

.include <bsd.port.mk>
