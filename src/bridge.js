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

// Determine if the current page is a chat URL
if(window.location.hostname === 'chat.stackexchange.com' &&
        window.location.pathname.match(/^\/rooms\/\d+/)) {

    // Hook all AJAX requests
    $(document).ajaxSuccess(function(e, jqXHR, ajaxOptions, data) {

        // Only process requests to /events
        if(ajaxOptions.url.match(/^\/events$/)) {

            // Loop over each of the keys
            $.each(data, function(key, value) {

                // Each key is of the format "r*" where "*" is the room number
                if(key.match(/r(\d+)/)) {

                    // Check for events
                    if('e' in value) {

                        // Loop over each of the events
                        $.each(value.e, function(index, event) {

                            // Event types:
                            // 1 - somebody posts a message
                            // 3 - user joins
                            // 4 - user leaves
                            // 8 - direct message
                            if(event.event_type === 1) {

                                // Print a diagnostic message
                                console.log('User ' + event.user_name + ' wrote "' + event.content + '".');
                            }
                        });
                    }
                }
            });
        }
    });
}
