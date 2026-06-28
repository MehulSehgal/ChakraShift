let shift = 3;

const shiftDisplay = document.getElementById("shiftDisplay");
const inputText = document.getElementById("inputText");
const results = document.getElementById("results");
const encryptedOutput = document.getElementById("encryptedOutput");
const decryptedOutput = document.getElementById("decryptedOutput");

document.getElementById("shiftUp").addEventListener("click", () => {
  if (shift < 25) {
    shift++;
    shiftDisplay.textContent = shift;
  }
});

document.getElementById("shiftDown").addEventListener("click", () => {
  if (shift > 1) {
    shift--;
    shiftDisplay.textContent = shift;
  }
});

function caesarShift(text, n) {
  return text.split("").map(ch => {
    if (/[a-zA-Z]/.test(ch)) {
      const base = ch === ch.toUpperCase() ? 65 : 97;
      return String.fromCharCode(((ch.charCodeAt(0) - base + n % 26 + 26) % 26) + base);
    }
    return ch;
  }).join("");
}

document.getElementById("encryptBtn").addEventListener("click", () => {
  const msg = inputText.value.trim();
  if (!msg) return;

  const encrypted = caesarShift(msg, shift);
  const decrypted = caesarShift(encrypted, -shift);

  encryptedOutput.textContent = encrypted;
  decryptedOutput.textContent = decrypted;
  results.style.display = "flex";
});

document.getElementById("decryptBtn").addEventListener("click", () => {
  const msg = inputText.value.trim();
  if (!msg) return;

  const decrypted = caesarShift(msg, -shift);
  const reEncrypted = caesarShift(decrypted, shift);

  encryptedOutput.textContent = reEncrypted;
  decryptedOutput.textContent = decrypted;
  results.style.display = "flex";
});

document.getElementById("clearBtn").addEventListener("click", () => {
  inputText.value = "";
  results.style.display = "none";
  encryptedOutput.textContent = "";
  decryptedOutput.textContent = "";
});

document.querySelectorAll(".copy-btn").forEach(btn => {
  btn.addEventListener("click", () => {
    const targetId = btn.getAttribute("data-target");
    const text = document.getElementById(targetId).textContent;
    navigator.clipboard.writeText(text).then(() => {
      btn.textContent = "Copied!";
      btn.classList.add("copied");
      setTimeout(() => {
        btn.textContent = "Copy";
        btn.classList.remove("copied");
      }, 1500);
    });
  });
});
