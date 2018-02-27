#ifndef SEQ64_QSEQTIME_HPP
#define SEQ64_QSEQTIME_HPP

/*
 *  This file is part of seq24/sequencer64.
 *
 *  seq24 is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  seq24 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with seq24; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * \file          qseqtime.hpp
 *
 *  This module declares/defines the base class for drawing the
 *  time/measures bar at the top of the patterns/sequence editor.
 *
 * \library       sequencer64 application
 * \author        Seq24 team; modifications by Chris Ahlstrom
 * \date          2018-01-01
 * \updates       2018-02-19
 * \license       GNU GPLv2 or above
 *
 */

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPen>

/*
 *  Do not document a namespace; it breaks Doxygen.
 */

namespace seq64
{
    class perform;

/**
 * The timebar for the sequence editor
 */

class qseqtime : public QWidget
{
    Q_OBJECT

public:

    explicit qseqtime (sequence & seq, QWidget * parent);
    void zoom_in ();
    void zoom_out ();

protected:
    //override painting event to draw on the frame
    void paintEvent(QPaintEvent *);

    //override mouse events for interaction
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

    //override the sizehint to set our own defaults
    QSize sizeHint() const;

signals:

private slots:

private:

    sequence & m_seq;
    QTimer * m_timer;
    QPen * m_pen;
    QBrush * m_brush;
    QPainter * m_painter;
    QFont m_font;
    int m_zoom;

};          // class qseqtime

}           // namespace seq64

#endif      // SEQ64_QSEQTIME_HPP

/*
 * qseqtime.hpp
 *
 * vim: sw=4 ts=4 wm=4 et ft=cpp
 */
