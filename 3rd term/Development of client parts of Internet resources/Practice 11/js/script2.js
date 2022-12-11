function changeColor(elem) {
  if (elem.style.background == "white") {
    elem.style.background = "red";
  } else {
    elem.style.background = "white";
  }
  return;
}

function clickCheck(button) {
  const el = document.createElement("div");
  el.textContent = "click block";

  el.style.backgroundColor = "salmon";
  el.style.width = "100vw";
  el.style.height = "100vh";
  el.id = "element";
  if (!document.getElementById("element")) {
    const box = document.getElementById("box");
    box.appendChild(el);
  }
  el.addEventListener("click", function handleClick(event) {
    document.querySelector("#element").onmousemove = function (pos) {
      let xPos = pos.offsetX;
      let yPos = pos.offsetY;
      let block = document.createElement("div");
      block.style.backgroundColor = "black";
      block.style.border = "2px solid white";
      block.style.borderRadius = "5px";
      block.style.width = "30px";
      block.style.height = "30px";
      block.style.position = "absolute";
      block.style.top = yPos + 5 + "px";
      block.style.left = xPos + "px";
      el.appendChild(block);
      button.addEventListener("click", () => {
        document.querySelector("#element").onmousemove = null;
      });
    };
  });
  clickCheck(button);
}
