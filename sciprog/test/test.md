1. `a = new int[5]; delete a+1;`
  - **(-)** `free(): invalid pointer`
2. `A &operator-(const A rhd){..}`
    - **(+)**
2. `A &operator-(int){..}`
    - **(+-)** nicht als `postfix-`, aber natürlich als `A-int`
2. `static var` in methods is global :(
