# $OpenBSD: Makefile,v 1.12 2017/11/08 11:49:09 jasper Exp $

COMMENT =	lightweight shipper for real-time network analytics

BEAT =		heartbeat
VERSION =	5.6.4

GH_ACCOUNT =	elastic
GH_PROJECT =	beats
GH_TAGNAME =	v${VERSION}

CONFIGS =	heartbeat.yml heartbeat.template.json \
		heartbeat.template-es2x.json \
		heartbeat.template-es6x.json

WANTLIB += c pthread

pre-configure:
	cp -R ${WRKDIST}/metricbeat/ ${WRKSRC}/../

.include <bsd.port.mk>
