/***************************************************************************
 *
 * Copyright (C) 2004 Roberto Selbach Teixeira <roberto@kde.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ***************************************************************************/

#ifndef KORRENT_H
#define KORRENT_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kapplication.h>
#include <kmainwindow.h>

#include "korrentview.h"

class KPrinter;
class KURL;

/**
 * This class serves as the main window for Korrent.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author Roberto Teixeira <roberto@kde.org>
 * @version 0.1
 */
class Korrent : public KMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    Korrent();

    /**
     * Default Destructor
     */
    virtual ~Korrent();

    /**
     * Use this method to load whatever file/URL you have
     */
    void load(const KURL& url);

protected:
    /**
     * Overridden virtuals for Qt drag 'n drop (XDND)
     */
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);

protected:
    /**
     * This function is called when it is time for the app to save its
     * properties for session management purposes.
     */
    void saveProperties(KConfig *);

    /**
     * This function is called when this app is restored.  The KConfig
     * object points to the session management config file that was saved
     * with @ref saveProperties
     */
    void readProperties(KConfig *);


private slots:
    void fileNew();
    void fileOpen();
    void fileSave();
    void fileSaveAs();
    void filePrint();
    void optionsConfigureToolbars();
    void optionsPreferences();
    void newToolbarConfig();

    void changeStatusbar(const QString& text);
    void changeCaption(const QString& text);

private:
    void setupAccel();
    void setupActions();

private:
    KorrentView *m_view;

    KPrinter   *m_printer;
};

#endif // KORRENT_H
