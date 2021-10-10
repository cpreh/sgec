#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/input/key/code.h>
#include <sge/input/key/code.hpp>
#include <fcppt/assert/unreachable.hpp>

sgec_input_key_code sgec::impl::input::key::translate_code(sge::input::key::code const _code)
{
#define TRANSLATE_CASE_BASE(cpp_name, c_name) \
  case sge::input::key::code::cpp_name: \
    return sgec_input_key_code_##c_name

#define TRANSLATE_CASE(name) TRANSLATE_CASE_BASE(name, name)

#define TRANSLATE_CASE_NUM(name) TRANSLATE_CASE_BASE(_##name, name)

  switch (_code)
  {
    TRANSLATE_CASE(escape);
    TRANSLATE_CASE_BASE(return_, return );
    TRANSLATE_CASE(left_shift);
    TRANSLATE_CASE(right_shift);
    TRANSLATE_CASE(tab);
    TRANSLATE_CASE(backspace);
    TRANSLATE_CASE(left_control);
    TRANSLATE_CASE(right_control);
    TRANSLATE_CASE(left_alt);
    TRANSLATE_CASE(right_alt);
    TRANSLATE_CASE(space);
    TRANSLATE_CASE(capital);
    TRANSLATE_CASE(insert);
    TRANSLATE_CASE(home);
    TRANSLATE_CASE(pageup);
    TRANSLATE_CASE_BASE(delete_, delete);
    TRANSLATE_CASE(end);
    TRANSLATE_CASE(pagedown);
    TRANSLATE_CASE(left);
    TRANSLATE_CASE(right);
    TRANSLATE_CASE(up);
    TRANSLATE_CASE(down);
    TRANSLATE_CASE(a);
    TRANSLATE_CASE(b);
    TRANSLATE_CASE(c);
    TRANSLATE_CASE(d);
    TRANSLATE_CASE(e);
    TRANSLATE_CASE(f);
    TRANSLATE_CASE(g);
    TRANSLATE_CASE(h);
    TRANSLATE_CASE(i);
    TRANSLATE_CASE(j);
    TRANSLATE_CASE(k);
    TRANSLATE_CASE(l);
    TRANSLATE_CASE(m);
    TRANSLATE_CASE(n);
    TRANSLATE_CASE(o);
    TRANSLATE_CASE(p);
    TRANSLATE_CASE(q);
    TRANSLATE_CASE(r);
    TRANSLATE_CASE(s);
    TRANSLATE_CASE(t);
    TRANSLATE_CASE(u);
    TRANSLATE_CASE(v);
    TRANSLATE_CASE(w);
    TRANSLATE_CASE(x);
    TRANSLATE_CASE(y);
    TRANSLATE_CASE(z);
    TRANSLATE_CASE_NUM(0);
    TRANSLATE_CASE_NUM(1);
    TRANSLATE_CASE_NUM(2);
    TRANSLATE_CASE_NUM(3);
    TRANSLATE_CASE_NUM(4);
    TRANSLATE_CASE_NUM(5);
    TRANSLATE_CASE_NUM(6);
    TRANSLATE_CASE_NUM(7);
    TRANSLATE_CASE_NUM(8);
    TRANSLATE_CASE_NUM(9);
    TRANSLATE_CASE(f1);
    TRANSLATE_CASE(f2);
    TRANSLATE_CASE(f3);
    TRANSLATE_CASE(f4);
    TRANSLATE_CASE(f5);
    TRANSLATE_CASE(f6);
    TRANSLATE_CASE(f7);
    TRANSLATE_CASE(f8);
    TRANSLATE_CASE(f9);
    TRANSLATE_CASE(f10);
    TRANSLATE_CASE(f11);
    TRANSLATE_CASE(f12);
    TRANSLATE_CASE(f13);
    TRANSLATE_CASE(f14);
    TRANSLATE_CASE(f15);
    TRANSLATE_CASE(comma);
    TRANSLATE_CASE(colon);
    TRANSLATE_CASE(decimal);
    TRANSLATE_CASE(apostrophe);
    TRANSLATE_CASE(backslash);
    TRANSLATE_CASE(grave);
    TRANSLATE_CASE(subtract);
    TRANSLATE_CASE(left_bracket);
    TRANSLATE_CASE(right_bracket);
    TRANSLATE_CASE(semicolon);
    TRANSLATE_CASE(slash);
    TRANSLATE_CASE(underline);
    TRANSLATE_CASE(scroll);
    TRANSLATE_CASE(pause);
    TRANSLATE_CASE(left_win);
    TRANSLATE_CASE(right_win);
    TRANSLATE_CASE(num_0);
    TRANSLATE_CASE(num_1);
    TRANSLATE_CASE(num_2);
    TRANSLATE_CASE(num_3);
    TRANSLATE_CASE(num_4);
    TRANSLATE_CASE(num_5);
    TRANSLATE_CASE(num_6);
    TRANSLATE_CASE(num_7);
    TRANSLATE_CASE(num_8);
    TRANSLATE_CASE(num_9);
    TRANSLATE_CASE(num_comma);
    TRANSLATE_CASE(num_enter);
    TRANSLATE_CASE(num_equals);
    TRANSLATE_CASE(num_lock);
    TRANSLATE_CASE(add);
    TRANSLATE_CASE(minus);
    TRANSLATE_CASE(multiply);
    TRANSLATE_CASE(divide);
    TRANSLATE_CASE(apps);
    TRANSLATE_CASE(circumflex);
    TRANSLATE_CASE(at);
    TRANSLATE_CASE(ax);
    TRANSLATE_CASE(equals);
    TRANSLATE_CASE(kana);
    TRANSLATE_CASE(kanji);
    TRANSLATE_CASE(convert);
    TRANSLATE_CASE(noconvert);
    TRANSLATE_CASE(period);
    TRANSLATE_CASE(power);
    TRANSLATE_CASE(sleep);
    TRANSLATE_CASE(stop);
    TRANSLATE_CASE(sysrq);
    TRANSLATE_CASE(unlabeled);
    TRANSLATE_CASE(yen);
    TRANSLATE_CASE(unknown);
  }

  FCPPT_ASSERT_UNREACHABLE;

#undef TRANSLATE_CASE
}
