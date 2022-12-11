document.querySelector(".for-trash").onmousedown = (event) => {
  if (event.target.id.includes("el")) {
    let currentDroppable = null;
    event.target.onmousedown = function (event) {
      event.target.style.position = "absolute";
      event.target.style.zIndex = 1000;

      document.body.append(event.target);

      function moveAt(pageX, pageY) {
        event.target.style.left = pageX - event.target.offsetWidth / 2 + "px";
        event.target.style.top = pageY - event.target.offsetHeight / 2 + "px";
      }

      moveAt(event.pageX, event.pageY);

      function onMouseMove(event) {
        function enterDroppable(elem) {
          if (elem.textContent === "0") {
            elem.textContent = (
              parseInt(elem.textContent) + parseInt(event.target.textContent)
            ).toString();
          } else {
            elem.textContent = (
              parseInt(elem.textContent) +
              parseInt(event.target.textContent) / 2
            ).toString();
          }
          event.target.onmousedown = null;
          event.target.remove();
        }
        moveAt(event.pageX, event.pageY);

        event.target.hidden = true;
        let elemBelow = document.elementFromPoint(event.clientX, event.clientY);
        event.target.hidden = false;

        if (!elemBelow) return;

        if (elemBelow.id === "trash") {
          enterDroppable(elemBelow);
        }
      }

      document.addEventListener("mousemove", onMouseMove);

      event.target.onmouseup = function () {
        document.removeEventListener("mousemove", onMouseMove);
        //event.target.onmouseup = null;
      };
    };
  }
};
