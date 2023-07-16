#pragma once
#define ColumnCount 8
namespace {
static const char* DateMask = "dd.MM.yyyy";
static const char* fsLastNameame_regex =
        "(^[A-Z])([A-Z|a-z|0-9| |-]*)([A-Z|a-z|0-9]$)";
static const char* email_regex =
        "(^[a-z|A-Z|0-9]+)@([a-z|A-Z|0-9]+\\.[a-z|A-Z|0-9]+$)";
static const char* phone_regex =
        "(\\+\\d{1,4}\\(\\d{4}\\)\\d{4}\\-\\d{2}\\-\\d{2}\\;";
}
