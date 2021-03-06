# $OpenBSD: Makefile,v 1.34 2017/10/10 12:04:59 sthen Exp $

COMMENT =	gateway to send and receive SMS through GSM mobile phones

DISTNAME =	smstools3-3.1.21

CATEGORIES =	comms

HOMEPAGE =	http://smstools3.kekekasvi.com/

MAINTAINER =	Stuart Henderson <sthen@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c mm

MASTER_SITES =	${HOMEPAGE}/packages/

RUN_DEPENDS =	mail/procmail # some scripts use formail(1)
LIB_DEPENDS =	devel/mm

USE_GMAKE =	Yes
NO_TEST =	Yes
WRKDIST =	${WRKDIR}/smstools3
WRKSRC =	${WRKDIST}/src

EXTRA_CFLAGS +=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAKE_FLAGS +=	CFLAGS="${CFLAGS} -D NUMBER_OF_MODEMS=64 -D DISABLE_INOTIFY `mm-config --cflags`"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smsd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIST}/scripts/{sendsms,sms2html} \
		${WRKDIST}/scripts/{sms2unicode,unicode2sms} \
		${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smstools \
		${PREFIX}/share/examples/smstools/scripts
	${INSTALL_DATA} ${WRKDIST}/examples/* \
		${PREFIX}/share/examples/smstools
	${INSTALL_DATA} ${WRKDIST}/scripts/* \
		${PREFIX}/share/examples/smstools/scripts
	rm ${PREFIX}/share/examples/smstools/scripts/*.orig
	${SUBST_DATA} ${FILESDIR}/smsd.conf.openbsd \
		${PREFIX}/share/examples/smstools/smsd.conf.openbsd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smstools
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smstools/slideshow
	${INSTALL_DATA} ${WRKDIST}/doc/*html ${PREFIX}/share/doc/smstools
	${INSTALL_DATA} ${WRKDIST}/doc/slideshow/* \
		${PREFIX}/share/doc/smstools/slideshow

.include <bsd.port.mk>
