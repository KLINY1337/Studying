function showRegAlert() {
  setTimeout(() => {}, 10000);
  let res = confirm("Желаете зайти на сайт?");
  if (res != false) {
    alert("Круто!");
    res = prompt("Введите логин.");
    if (res == "Админ") {
      let pass = prompt("Введите пароль.");
      if (pass != "123" && pass != null) {
        alert("Неверно, попробуйте еще раз.");
        return;
      } else if (pass == null) {
        alert("Отменено");
        return;
      } else if (pass == "123") alert("Здравствуйте");
    } else {
      alert("Неверно, попробуйте еще раз.");
      return;
    }
  } else {
    alert("Попробуйте еще раз");
    return;
  }
  return true;
}
while (!showRegAlert()) {}
