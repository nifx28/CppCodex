/*
 * 金字塔建築師：工具包。
 */

// 只引入一次標頭檔的新標示方式。
#pragma once

// 開頭：只引入一次標頭檔的傳統方式。
#ifndef PYRAMID_TOOLSET_H
#define PYRAMID_TOOLSET_H

void setmode(int mode);

// 開頭：給 C 呼叫的函式，不支援 C++ 的函式裝飾方式。
#ifdef __cplusplus
extern  "C" {
#endif

void print(size_t num, size_t offset = 0);

// 結束：給 C 呼叫的函式，不支援 C++ 的函式裝飾方式。
#ifdef __cplusplus
}
#endif

// 結束：只引入一次標頭檔的傳統方式。
#endif /* PYRAMID_TOOLSET_H */
