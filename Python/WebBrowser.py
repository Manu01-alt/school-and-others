 from PyQt6.QtWidgets import QApplication, QMainWindow, QHBoxLayout, QVBoxLayout, QWidget, QPushButton, QLineEdit, QLabel
from PyQt6.QtWebEngineWidgets import QWebEngineView
from PyQt6.QtWebEngineCore import QWebEngineProfile
from PyQt6.QtCore import QUrl, Qt
import sys

class WebBrowser(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My PyQt Browser")
        self.setGeometry(100, 100, 800, 600)

        # Creazione di un profilo per gestire i cookie
        self.profile = QWebEngineProfile.defaultProfile()
        
        self.browser = QWebEngineView()
        self.browser.setUrl(QUrl("https://www.google.com"))
        
        self.url_bar = QLineEdit()
        self.url_bar.returnPressed.connect(self.load_url)
        
        self.back_button = QPushButton("◀")
        self.back_button.setFixedSize(30, 30)
        self.back_button.clicked.connect(self.browser.back)
        
        self.forward_button = QPushButton("▶")
        self.forward_button.setFixedSize(30, 30)
        self.forward_button.clicked.connect(self.browser.forward)
        
        self.reload_button = QPushButton("⟳")
        self.reload_button.setFixedSize(30, 30)
        self.reload_button.clicked.connect(self.browser.reload)
        
        top_layout = QHBoxLayout()
        top_layout.addWidget(self.back_button)
        top_layout.addWidget(self.forward_button)
        top_layout.addWidget(self.reload_button)
        top_layout.addWidget(self.url_bar)
        
        main_layout = QVBoxLayout()
        main_layout.addLayout(top_layout)
        main_layout.addWidget(self.browser)
        
        container = QWidget()
        container.setLayout(main_layout)
        container.setStyleSheet("background-color: rgba(0, 0, 50, 0.5);")  # Imposta il colore di sfondo a blu più scuro e più trasparente
        self.setCentralWidget(container)
    
    def load_url(self):
        url = self.url_bar.text()
        if not url.startswith("http"):
            url = "https://" + url
        self.browser.setUrl(QUrl(url))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = WebBrowser()
    window.show()
    sys.exit(app.exec())
