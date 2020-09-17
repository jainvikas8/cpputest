#include "string.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(sprintf)
{
    char output[100];
    const char *expected;

    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }

    void teardown()
    {

    }

    void expect(const char *s)
    {
        expected = s;
    }

    void given(int chars_written)
    {
        LONGS_EQUAL(strlen(expected), chars_written);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};

TEST(sprintf, No_Format_Oprations)
{
    expect ("hey");
    given(sprintf(output, "hey"));
}

TEST(sprintf, Insert_string)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}
