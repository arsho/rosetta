// BUILD: add_benchmark(ppm=serial)

#include "rosetta.h"

static real kernel(pbsize_t n) {
  real sum = 0;
  // FIXME: Compilers may solve this recurrence equation with fast-math enable
  for (idx_t i = 0; i < n; i += 1)
    sum += i;
  return sum;
}

void run(State &state, pbsize_t n) {
  auto sum_owner = state.allocate_array<real>({1}, /*fakedata*/ false, /*verify*/ true, "sum");
  multarray<real, 1> sum = sum_owner;

  for (auto &&_ : state) {
    sum[0] = kernel(n);
  }
}
