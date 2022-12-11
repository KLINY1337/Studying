let list = document.querySelectorAll("a");

for (let el of list) {
  el.style.color = "red";
}

function createUl() {
  let list = document.createElement("ul");
  document.body.appendChild(list);
  let res = prompt("Введите содержимое пункта");
  while (res != null && res != "") {
    let el = document.createElement("li");
    el.textContent = res;
    list.appendChild(el);
    res = prompt("Введите содержимое пункта");
  }
}

function ShowNotification(options) {
  let div = document.createElement("div");
  div.setAttribute("class", "notification");
  div.id = "notif";
  div.style.width = "400px";
  div.style.height = "200px";
  div.style.position = "fixed";
  div.style.top = "50%";
  div.style.left = "50%";
  div.style.transform = "translate(-50%,-50%)";
  div.style.backgroundColor = "black";
  div.style.color = "white";
  div.textContent = options;
  div.style.zIndex = "1000";
  document.getElementById("notification-div").appendChild(div);
  setInterval(() => {
    div.remove();
  }, 3000);
}

document.getElementById("picture-div").style.display = "none";

function showPicture() {
  let div = document.getElementById("picture-div");
  div.style.display = "block";
  div.style.width = "50vw";
  div.style.height = "50vh";
  div.style.backgroundColor = "red";
  div.style.position = "fixed";
  div.style.top = "50%";
  div.style.left = "50%";
  div.style.transform = "translate(-50%,-50%)";
  let img = document.createElement("img");
  img.setAttribute("src", "/Assets/Images/blockchain.png");
  img.setAttribute("width", "50%");
  img.setAttribute("height", "50%");
  img.style.zIndex = "1020";
  img.style.display = "block";
  img.style.position = "relative";
  img.style.top = "50%";
  img.style.left = "50%";
  img.style.transform = "translate(-50%,-50%)";
  div.appendChild(img);

  img.addEventListener("click", function handleClick(event) {
    img.onmousemove = function (pos) {
      let xPos = pos.offsetX;
      let yPos = pos.offsetY;
      alert(xPos + " " + yPos);
      img.onmousemove = null;
    };
  });
}

document.getElementById("notification-div").onclick = function (event) {
  let target = event.target;

  if (target.id != "notif") return;
  else {
    target.onclick = () => {
      console.log(target.textContent);
      target.remove();
    };
  }
};
