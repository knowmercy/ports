# $OpenBSD: Makefile,v 1.35 2017/05/16 19:34:50 landry Exp $

COMMENT =	continuous integration framework

MODPY_EGG_VERSION =	0.8.12
DISTNAME =	buildbot-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:S/p/pl/}
REVISION =	6

CATEGORIES =	devel

HOMEPAGE =	http://buildbot.net/

MAINTAINER =	Landry Breuil <landry@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

MODPY_PI =	Yes

MODULES =	lang/python

MODPY_SETUPTOOLS = Yes

RUN_DEPENDS =	databases/py-sqlalchemy \
		databases/py-sqlalchemy-migrate>=0.7.2 \
		devel/py-dateutil \
		devel/py-twisted \
		www/py-jinja2

TEST_DEPENDS =	${RUN_DEPENDS} \
			devel/py-mock

HOMEDIR =		/var/buildbot

SUBST_VARS +=		HOMEDIR

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-buildbot
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-buildbot
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-buildbot
	${INSTALL_DATA} ${WRKSRC}/docs/examples/*.cfg \
	    ${PREFIX}/share/examples/py-buildbot
	cd ${WRKSRC} && pax -rw contrib ${PREFIX}/share/doc/py-buildbot
	${INSTALL_MAN} ${WRKSRC}/docs/buildbot.1 ${PREFIX}/man/man1

do-test:
	@${MAKE_ENV} PYTHONPATH=${WRKSRC} \
	    ${LOCALBASE}/bin/trial --temp-directory=${WRKBUILD}/regress \
	    buildbot.test

.include <bsd.port.mk>
