var len;
var arr = new Array();

function createArr() {
  len = prompt("Сколько элементов в массиве?");

  let i = 0;
  for (i = 0; i < len; i++) {
    block = document.createElement("div");
    block.textContent = String(i);
    block.id = "array-" + String(i);
    block.style.display = "inline-block";
    block.style.padding = "5px";
    block.style.width = "50px";
    block.style.height = "50px";
    document.getElementById("array-container").appendChild(block);
    arr.push(block);
  }
}

function swapElements() {
  let el1Num = prompt("Введите значение 1 для обмена");
  let el2Num = prompt("Введите значение 2 для обмена");

  let el1 = document.getElementById("array-" + el1Num);
  let el2 = document.getElementById("array-" + el2Num);

  let tmp = el1.textContent;
  el1.textContent = el2.textContent;
  el2.textContent = tmp;

  tmp = arr[el1Num];
  arr[el1Num] = arr[el2Num];
  arr[el2Num] = tmp;
}

function deleteFirst() {
  let el = findMinimal();
  el.remove();
  arr.shift(); //удаление первого элемента
}

function findMinimal() {
  let i = 0;
  for (i = 0; i < len; i++) {
    if (document.getElementById("array-" + String(i)) != null) {
      return document.getElementById("array-" + String(i));
    }
  }
}

function handleFilter() {
  let a = prompt("Введите минимальное значение");
  let b = prompt("Введите максимальное значение");

  let arrFiltered = filter(parseInt(a), parseInt(b));
  console.log(arrFiltered);
  for (let i = 0; i < arrFiltered.length; i++) {
    document
      .getElementById("filtered-array-container")
      .appendChild(arrFiltered[i]);
  }
}

function filter(min, max) {
  let fArr = new Array();
  for (let i = 0; i < len; i++) {
    if (
      parseInt(arr[i].textContent) >= min &&
      parseInt(arr[i].textContent) <= max
    ) {
      let clone = arr[i].cloneNode(true);
      clone.id = "af-" + String(i);
      fArr.push(clone);
    }
  }
  return fArr;
}

function sort() {
  arr.sort((a, b) => {
    return parseInt(a.textContent) - parseInt(b.textContent);
  });
  console.log(arr);
}
