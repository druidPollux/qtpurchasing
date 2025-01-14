/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Purchasing module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3-COMM$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qandroidinappproduct_p.h"
#include "qandroidinapppurchasebackend_p.h"

QT_BEGIN_NAMESPACE

QAndroidInAppProduct::QAndroidInAppProduct(QAndroidInAppPurchaseBackend *backend,
                                           const QString &price,
                                           const QString &title,
                                           const QString &description,
                                           ProductType productType,
                                           const QString &identifier,
                                           QObject *parent)
    : QInAppProduct(price, title, description, productType, identifier, parent)
    , m_backend(backend)
{
   m_type = QStringLiteral("inapp");
}


void QAndroidInAppProduct::purchase()
{
    m_backend->purchaseProduct(this);
}

void QAndroidInAppProduct::setType( const QString &type )
{
    if ( type == QStringLiteral("inapp") || type == QStringLiteral("subs") )
       m_type = type;
}

QString QAndroidInAppProduct::type() const
{
   return m_type; 
}

QT_END_NAMESPACE

