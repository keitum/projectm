/***************************************************************************
 *   Copyright (C) 2007 by carm   *
 *   carmelo.piccione@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef QPROJECTM_PLAYLISTMODEL_H
#define QPROJECTM_PLAYLISTMODEL_H

#include <cassert>
#include "libprojectM/projectM.hpp"

#include <QAbstractTableModel>

 class QPlaylistModel : public QAbstractTableModel
 {
     Q_OBJECT        // must include this if you use Qt signals/slots

 public:
static const int URLInfoRole = 1000;
     QPlaylistModel(projectM & _projectM, QObject * parent = 0);
     ~QPlaylistModel() { }

void appendRow (const QString & presetURL, const QString & presetName);
void removeRow (int index);
QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

void clear();

QVariant data ( const QModelIndex & index, int role) const;
int rowCount ( const QModelIndex & parent = QModelIndex()) const ;
int columnCount ( const QModelIndex & parent) const ;


 private:
	projectM & m_projectM;
	
};
#endif
