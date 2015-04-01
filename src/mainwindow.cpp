/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <QLineEdit>

#include "cookiejar.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    setupUi(this);

    webView->page()->networkAccessManager()->setCookieJar(new CookieJar);

    connect(webView, SIGNAL(loadFinished(bool)), progressBar, SLOT(hide()));
    connect(webView, SIGNAL(loadProgress(int)), progressBar, SLOT(setValue(int)));
    connect(webView, SIGNAL(loadStarted()), progressBar, SLOT(show()));
    connect(webView, SIGNAL(urlChanged(QUrl)), this, SLOT(onUrlChanged(QUrl)));

    connect(urlEdit, SIGNAL(returnPressed()), this, SLOT(loadUrl()));
    connect(goButton, SIGNAL(clicked()), this, SLOT(loadUrl()));
}

void MainWindow::onUrlChanged(const QUrl &url)
{
    urlEdit->setText(url.toString());
}

void MainWindow::loadUrl()
{
    // Be nice and add the 'http://' prefix if it is missing
    QString url = urlEdit->text();
    if(!url.startsWith("http://") && !url.startsWith("https://")) {
        url = "http://" + url;
    }

    webView->setUrl(QUrl(url));
}
