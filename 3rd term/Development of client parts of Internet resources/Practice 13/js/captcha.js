function handleSend(el) {
  let cap = document.getElementById("captcha");
  cap.style.visibility = "visible";
  let str = document.querySelector(".str"); // Берём элемент строки
  let btn = document.querySelector(".btn"); // Берём элемент кнопки
  let txt = document.querySelector(".text");

  let num1 = Math.ceil(Math.random() * 10); // Получаем рандомное число один
  let num2 = Math.ceil(Math.random() * 10); // Получаем рандомное число два
  let res = num1 + num2; // Результат сложение этих чисел

  // Выводим строчку ворожения
  str.innerHTML = `${num1} + ${num2} = `;
  str.style.textAlign = "center";
  // События нажатия на кнопку
  btn.addEventListener("click", function () {
    // Получаем значение из input
    let inputNum = document.querySelector(".input-num").value;
    // Переводим в числовой тип данныхi

    inputNum = parseInt(inputNum);
    // Условие, если значение из input равно результат
    if (inputNum === res) {
      txt.innerHTML = "Капча правильная)";
      cap.style.visibility = "hidden";
      // То выводит в консоль "Вход разрешён"
    } else {
      // Иначе выводит "Вход запрещен"
      txt.innerHTML = "Капча неправильная(";
      num1 = Math.ceil(Math.random() * 10);
      num2 = Math.ceil(Math.random() * 10);
      str.innerHTML = `${num1} + ${num2} = `;
      res = num1 + num2;
    }
  });
}
