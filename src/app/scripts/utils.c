/**
 * src/app/scripts/utils.c -- JavaScript API: utility
 *
 *
 * @author sskaje
 * @license MIT
 * ------------------------------------------------------------------------
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 - , sskaje (https://sskaje.me/)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * ------------------------------------------------------------------------
 */

#include "../scripts.h"

duk_ret_t native_integer_add(duk_context *ctx)
{
    // todo: 32bit cpu ?
    // 0x0123456789abcdef
    char tmp_address[20] = {0};

    int64_t a = duk_require_int64(ctx, 0);
    int64_t b = duk_require_int64(ctx, 1);

    sprintf(tmp_address, "0x%llx", a + b);
    duk_push_string(ctx, tmp_address);

    return 1;
}

duk_ret_t native_integer_subtract(duk_context *ctx)
{
    // todo: 32bit cpu ?
    // 0x0123456789abcdef
    char tmp_address[20] = {0};

    int64_t a = duk_require_int64(ctx, 0);
    int64_t b = duk_require_int64(ctx, 1);

    sprintf(tmp_address, "0x%llx", a - b);
    duk_push_string(ctx, tmp_address);

    return 1;
}

void script_utils_register(duk_context *ctx)
{
    duk_push_c_function(ctx, native_integer_add, 2);
    duk_put_prop_string(ctx, -2, "mh_integer_add");

    duk_push_c_function(ctx, native_integer_subtract, 2);
    duk_put_prop_string(ctx, -2, "mh_integer_sub");

}

// EOF
