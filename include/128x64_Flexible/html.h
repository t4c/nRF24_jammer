#ifndef HTML_H
#define HTML_H

static const char *const html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
            --danger: #f85149;
            --warning: #f0883e;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
        }
        
        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(10px); }
            to { opacity: 1; transform: translateY(0); }
        }
        
        .view {
            display: none;
            width: 100%;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            flex: 1;
            padding: 20px;
        }
        
        .view.active {
            display: flex;
            animation: fadeIn 0.4s ease-out forwards;
        }
        
        .header-main {
            width: 100%;
            max-width: 800px;
            padding: 30px 0;
            display: flex;
            justify-content: space-between;
            align-items: center;
            border-bottom: 1px solid var(--border);
            margin-bottom: 30px;
            margin-top: 20px;
        }
        
        .logo {
            height: 50px;
            object-fit: contain;
            animation: float 3s ease-in-out infinite;
        }
        
        @keyframes float {
            0%, 100% { transform: translateY(0) scale(1); }
            50% { transform: translateY(-5px) scale(1.02); }
        }
        
        .btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 12px 24px;
            border-radius: 6px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-decoration: none;
            display: inline-block;
        }
        
        .btn:hover {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-2px) scale(1.02);
            box-shadow: 0 8px 20px rgba(88, 166, 255, 0.2);
        }
        
        .btn-large {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);

            padding: 16px 24px;
            border-radius: 8px;
            font-size: 15px;
            display: flex;
            align-items: center;
            justify-content: space-between;
            width: 100%;
            margin-bottom: 12px;
        }

        .btn-large:hover {
            border-color: var(--accent);
            transform: translateY(-2px);
            box-shadow: 0 6px 16px rgba(88, 166, 255, 0.15);
        }
        
        .btn-large.action {
            border-color: var(--accent);
            justify-content: center;
            gap: 8px;
        }
        
        .btn-large.action:hover {
            background: #4493f8;
            border-color: #4493f8;
        }
        
        .module-list {
            width: 100%;
            max-width: 800px;
            display: flex;
            flex-direction: column;
            gap: 12px;
            margin-bottom: 40px;
        }
        
        .module-item {
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 8px;
            padding: 20px 24px;
            cursor: pointer;
            transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
            display: flex;
            justify-content: space-between;
            align-items: center;
            opacity: 0;
            transform: translateX(-20px);
            animation: slideIn 0.4s cubic-bezier(0.4, 0, 0.2, 1) forwards;
        }
        
        .module-item:nth-child(1) { animation-delay: 0.1s; }
        .module-item:nth-child(2) { animation-delay: 0.15s; }
        .module-item:nth-child(3) { animation-delay: 0.2s; }
        .module-item:nth-child(4) { animation-delay: 0.25s; }
        .module-item:nth-child(5) { animation-delay: 0.3s; }
        .module-item:nth-child(6) { animation-delay: 0.35s; }
        .module-item:nth-child(7) { animation-delay: 0.4s; }
        
        @keyframes slideIn {
            to { opacity: 1; transform: translateX(0); }
        }
        
        .module-item:hover {
            border-color: var(--accent);
            transform: translateX(8px) scale(1.02);
            box-shadow: 0 6px 16px rgba(88, 166, 255, 0.15);
        }
        
        .module-item.disabled {
            opacity: 0.4;
            cursor: not-allowed;
        }
        
        .module-item.disabled:hover {
            transform: none;
            border-color: var(--border);
            box-shadow: none;
        }
        
        .module-info {
            flex: 1;
        }
        
        .module-name {
            font-size: 16px;
            font-weight: 600;
            margin-bottom: 4px;
        }
        
        .module-desc {
            font-size: 13px;
            color: var(--text-secondary);
        }
        
        .module-channels {
            font-size: 13px;
            color: var(--accent);
            font-weight: 500;
            padding: 4px 10px;
            background: rgba(88, 166, 255, 0.1);
            border-radius: 4px;
            border: 1px solid rgba(88, 166, 255, 0.2);
        }
        
        .config-warning {
            background: rgba(240, 136, 62, 0.1);
            border: 1px solid var(--warning);
            border-radius: 8px;
            padding: 16px;
            margin-bottom: 20px;
            display: none;
            align-items: flex-start;
            gap: 12px;
            animation: pulse 2s infinite;
        }
        
        @keyframes pulse {
            0%, 100% { opacity: 1; }
            50% { opacity: 0.9; }
        }
        
        .warning-icon {
            color: var(--warning);
            font-size: 20px;
        }
        
        .warning-title {
            font-size: 14px;
            font-weight: 600;
            margin-bottom: 4px;
            color: var(--warning);
        }
        
        .warning-text {
            font-size: 13px;
            color: var(--text-secondary);
            margin-bottom: 12px;
        }
        
        .warning-btn {
            background: var(--warning);
            border: 1px solid var(--warning);
            color: white;
            padding: 6px 14px;
            border-radius: 4px;
            font-size: 13px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.2s;
            text-decoration: none;
            display: inline-block;
        }
        
        .warning-btn:hover {
            opacity: 0.9;
            transform: translateY(-1px);
        }
        
        .sub-container {
            width: 100%;
            max-width: 500px;
            padding: 30px;
            border-radius: 12px;
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
            display: flex;
            flex-direction: column;
            gap: 24px;
        }
        
        .sub-header {
            text-align: center;
        }
        
        .method-info {
            text-align: left;
        }
        
        .method-name {
            font-size: 16px;
            font-weight: 600;
            margin-bottom: 4px;
        }
        
        .method-desc {
            font-size: 13px;
            color: var(--text-secondary);
        }
        
        .back-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 24px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 8px;
            width: 100%;
            margin-top: 10px;
        }
        
        .back-btn:hover {
            background: var(--bg-primary);
            border-color: var(--accent);
            transform: translateY(-2px);
        }
        
        .input-group {
            display: flex;
            flex-direction: column;
            gap: 8px;
            width: 100%;
        }
        
        .input-row {
            display: flex;
            gap: 12px;
            width: 100%;
        }
        
        .input-wrapper {
            flex: 1;
            display: flex;
            flex-direction: column;
            gap: 6px;
        }
        
        .input {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 16px;
            border-radius: 8px;
            font-size: 16px;
            transition: all 0.2s;
            width: 100%;
        }
        
        .input:focus {
            outline: none;
            border-color: var(--accent);
            box-shadow: 0 0 0 2px rgba(88, 166, 255, 0.2);
        }
        
        .input.invalid {
            border-color: var(--danger);
            box-shadow: 0 0 0 2px rgba(248, 81, 73, 0.2);
        }
        
        .label {
            font-size: 14px;
            color: var(--text-secondary);
            font-weight: 500;
        }
        
        .toggle {
            display: inline-flex;
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 9999px;
            padding: 5px;
            box-shadow: 0 4px 12px rgba(0, 0, 0, 0.25);
            margin: 0 auto;
        }
        
        .toggle-btn {
            padding: 10px 32px;
            font-size: 15px;
            font-weight: 600;
            color: var(--text-secondary);
            background: transparent;
            border: none;
            border-radius: 9999px;
            cursor: pointer;
            transition: all 0.35s cubic-bezier(0.4, 0, 0.2, 1);
            white-space: nowrap;
        }
        
        .toggle-btn.active {
            color: var(--text-primary);
            background: var(--accent);
            box-shadow: 0 4px 14px rgba(88, 166, 255, 0.35);
            transform: scale(1.05);
        }
        
        .options {
            display: flex;
            flex-direction: column;
            opacity: 1;
            transform: translateY(0);
            transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
        }
        
        .options.hidden {
            opacity: 0;
            transform: translateY(12px);
            display: none;
        }

        .channel-display-container {
            display: flex;
            align-items: center;
            gap: 10px;
            margin-top: 10px;
        }
        
        .channel-display {
            background: var(--bg-card);
            border: 1px solid var(--border);
            padding: 16px;
            border-radius: 8px;
            font-size: 14px;
            text-align: center;
            flex: 1;
            display: none;
        }
        
        .rescan-btn {
            background: var(--bg-card);
            border: 1px solid var(--accent);
            color: var(--text-primary);
            padding: 12px 16px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            display: none;
            white-space: nowrap;
        }
        
        .rescan-btn:hover {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-2px);
            box-shadow: 0 4px 12px rgba(88, 166, 255, 0.2);
        }

        #ssidListContainer {
            margin-top: 15px;
        }

        #ssidList {
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 8px;
            padding: 10px;
            max-height: 200px;
            overflow-y: auto;
            font-size: 14px;
            color: var(--text-primary);
        }
        
        .notification {
            position: fixed;
            top: -100px;
            left: 50%;
            transform: translateX(-50%);
            padding: 14px 24px;
            border-radius: 0 0 8px 8px;
            color: white;
            font-weight: 500;
            z-index: 3000;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.2);
            transition: top 0.5s ease-out;
            width: 90%;
            max-width: 400px;
            text-align: center;
            opacity: 0;
            animation: notificationFadeIn 0.3s forwards;
        }
        
        @keyframes notificationFadeIn {
            to { opacity: 1; }
        }
        
        .success { background: linear-gradient(135deg, var(--accent), #2ea043); }
        .error { background: linear-gradient(135deg, var(--danger), #da3633); }
        
        .confirm-dialog {
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            border-radius: 12px;
            padding: 24px;
            z-index: 2000;
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.4);
            width: 90%;
            max-width: 400px;
            display: none;
            opacity: 0;
            animation: dialogFadeIn 0.3s forwards;
        }
        
        @keyframes dialogFadeIn { to { opacity: 1; } }
        
        .confirm-dialog h3 {
            margin-bottom: 16px;
            font-size: 18px;
        }
        
        .confirm-dialog p {
            margin-bottom: 24px;
            color: var(--text-secondary);
            font-size: 14px;
        }
        
        .confirm-buttons {
            display: flex;
            gap: 12px;
        }
        
        .confirm-btn {
            flex: 1;
            padding: 12px 20px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.2s;
            text-align: center;
            border: none;
        }
        
        .confirm-btn.cancel {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
        }
        
        .confirm-btn.cancel:hover {
            background: var(--bg-primary);
            border-color: var(--accent);
        }
        
        .confirm-btn.accept {
            background: var(--accent);
            border: 1px solid var(--accent);
            color: white;
        }
        
        .confirm-btn.accept:hover {
            background: #4493f8;
            border-color: #4493f8;
        }
        
        .overlay {
            position: fixed;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background: rgba(0, 0, 0, 0.7);
            z-index: 1999;
            display: none;
            opacity: 0;
            animation: overlayFadeIn 0.3s forwards;
        }
        
        @keyframes overlayFadeIn { to { opacity: 1; } }
        
        @media (max-width: 768px) {
            .view { padding: 15px; }
            .header-main { padding: 20px 0; margin-bottom: 20px; flex-direction: column; gap: 15px; }
            .logo { height: 40px; }
            .module-list { gap: 10px; margin-bottom: 30px; }
            .module-item { padding: 16px; }
            .sub-container { padding: 20px; }
        }
        
        @media (max-width: 480px) {
            .view { padding: 10px; }
            .header-main { padding: 15px 0; margin-bottom: 15px; }
            .logo { height: 35px; }
            .btn { padding: 10px 16px; font-size: 13px; }
            .module-item { padding: 14px; }
            .module-name { font-size: 15px; }
            .module-desc { font-size: 12px; }
            .toggle-btn { padding: 10px 20px; font-size: 13px; }
        }
    </style>
</head>
<body>

    <div id="notification" class="notification" style="display: none;"></div>
    <div id="overlay" class="overlay" style="display: none;"></div>
    <div id="confirmDialog" class="confirm-dialog" style="display: none;">
        <h3 id="confirmTitle">Confirm Action</h3>
        <p id="confirmMessage">Are you sure you want to perform this action?</p>
        <div class="confirm-buttons">
            <button class="confirm-btn cancel" onclick="hideConfirmDialog()">Cancel</button>
            <button class="confirm-btn accept" onclick="confirmAction()">Confirm</button>
        </div>
    </div>

    <div id="view-main" class="view active">
        <div class="header-main">
            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFAAAABDCAYAAAALU4KYAAAACXBIWXMAAEuqAABLqgE8yTPtAAALz0lEQVR4nOScaWwV1xXHxywJhNAogMW+GLMZg40NxmBWP2OwDWYxizGL8QYYDFSEtlQiaT4kSFWktIqqVEm/pIoiVZVKokZNAIXQpnuj5kNpKiqRJg0SaQNNEahJ1aSS+/9N37EmUz+/ee/NWygf/rqzv7m/d+455965M87s2bOdkpISZ+HChc6SJUucxYsXO1VVVc7KlSudFStWpCyus2zZMqeystJZtGiRU15e3rR06dIzWv+jdE26Ip3Vto6Kiop7OE7LTllZmXvOjh07nD179rjauXOns2HDhuFtbW2HOjs7X9+/f/9V6aOurq4/tbe3v9za2rpLx+TV19c769evd7Zs2eJs3rw5ZW3cuNHZtm2bo+u799Dc3OyKfU4sgJFIxKmurg5FABScIl3/D4LS25+0r1e//YHgdWp9KAC5F268paUFAa6no6PjxqFDh3q7u7t7Dx486Ipl23bgwIF3VeEFQGxqanIrn6r0pwUHaBagCqcsLI7r6Q+pFox+wfkhIi3f0rmvqnxGN/1dWdjr0sdAQoIUU4cPH3aPUYXrscLt27e7lU9FW7duda8TCCDw+OcnTZrkjB071hk/fnzSys/PdwoKCgp1zX/Eg+cHKYC9Os+1sCNHjph1xZWatAtRwP+lChZp3dFy0uJ8Wb0LztxIXAukCS9YsMCFOGXKlKQ0efJk93xd9yVdLzA8k85zQRqQIPD8lig/eRbrwY8mKyxv9+7dzq5du4IDxAop2ZZK81W5AitKFF4YALFcmrL8YE1dXZ3rxxIVLgAfCLyEAJqwRAJAstL5P0oGXhgAzQoVnS9QUSwxURGECGB79+51y8AAvZbIvqlTpzrTpk0LLJrvnDlzViXTdMMEiLBCVb4OGDTHoCJ40ITN8pICiPCFyt1caySvW758+YDiGMCrCf8wWXhhAuRcRc9zAAEA/mwgcQxwsEBgGbiUAJIMA4fcjOMGEscIYImacG+Q1CXdAC2Kyw+Wk13EMwDqvHbtWjdlAZpF35QAGjyaJ8erefaroqIip7Cw0Jk7d+6TqTTfMAFy/rFjx3o3bdr0LeoVL+mnrgQQ/B6wQgFIk8QKacZAmjVrlnueXzNmzHDmz5//BVnfB6nACxOgJyJfl1WNAgzWFUsKOo56PH3wQgEIOP4Z0hOzQED6xfbi4uK2ymgynCsAzRcKwv7Gxka3j+wX6QrBA0gEDmu+oQFE+BAsEVOn9Gv16tUEkXOp+L50ApRlXbTczt/XBca+ffvSD9D2sVzpyRmj22aEAS8dAOkKIgWIufzRNTU1rjAGSoDQfK3XkVaA+ETkT190zFdyFaBZoeA8Ys0YAAoufXDwgRkBaMt+C5R+Hga8dAEkqe7o6PgtSTV5oSXNNt6YUYCeZut222SRRWFZX7oAEo0pBaIUUNFxRhcY61kBSFOeMGEC1/mymnJOA0THjx/vra2tfZh6G8SsAySFKS0t/UWqyXMmAB49erRXEN6MRCJDDARQgEaOmDaANFMBHKp98wVtl/adll6ULsnybgIv15sw6urqcrt26p18In94WZH3VaU33xC8dqUxFYJ3H5AYSDC4SY/GSEPKy8uXa/1h6RUB+mtYgLIF0OsP7RGB9/mKAN8U2IuC+bhgrhGo4VhkIiPSg1Q2qHxBumE9ijCtKxcAxoJq+SJgo0BvC+gZwduq5n0PUft/AKr/CsB71TS/pJv/MJOgcglgPKi6l78r0DwqeCNIg1yADACUlZXV6GZvptp//X8E6BUQo/fyiZr1ehJy4G3muUWyzy7uJoBekDRx+cMdRNi3csny7gSABlHN+xKB42K2Yd2JALkn3dvPADhb+lu2gd1JAKP3c1u54nx7AJSvNOWcZ2pF1pVrAL15o5LvN5qamiYylugC9OSAiwXzJZX/vpsB8puUvklLgDuvXskKckFSGEZ1zAL7ZiOQE2p9jNYPqAIva9ttkui7JZEGGL8Xzfv+2dnZ+Zpyv2Pqyo0HnPVKgMeYYh9A677RKzGg9IFLS0uHa7laekQQAXr1TgZoibHB8k5aUq/jQ/U6zgvSafm3egF6wKZ1eB9xBgZoMxNsqkZ0EDVPZaG0UcsP6bzvqLxQ+d+Jkh8PBCUR/2oAqVhPT09fX9XG9Lzr3nmClGZB3l6EgRKkz6Sr0hvq7z7f1tZ2SuU2ddOKBWcocPBtjFQDyAZb/f3hwABlgd7RmL5BVBva8j4jqaioGK31EpXrtK1dyydVflN6TnpF23+l8m3pXYmBidvSZ8kA9PirT1VeF5Brsp4rKt8UlJ9q+Xtqfk/Lbz2qJnhYgBpV+QqVk9QVG8wIC00Sy7KH6GwDFHBMNpsh7QBtO+s8/qz0DYvZtaLXGKJ9I1WOUTlJ5UypRNKpFUtVLlPJKNBq5rXopteq0jW68WpVukpwSgRnnvqjRURDQRwpaPdpfTAPhnDwVNIeEtk0NRs8ZR9P4CjZz7KNB3JMVgACzaZ32DEG0Y5njo13u/8PsGPteqwz6sHN03nnpoHDOlbDPuAAgIfh/sFQtgORbTaCwpwXSpttmlWA7Oc8jjd4qvhUHVOr/VNU3q/9eTZn0I71ArNls1KbIWv3BBg1UXe2KJWnA4+PYpl9VJ7KAIR1QJvVqbKDBPBB7ZsuAA3SdBuO4hgbLM0JC/RYVKPHlzE0dlnH/lo6q+XnVT6t8uvSKR17XGU3/lLart9r1LY6/gDdAyNEETXVWgWAtYJYq4rUq/I7VIEOLR8WnKNqzg+pUo9p+Sktf1vlGZ3zYy2/pfIdNe+bltPpvO32RA4BABjAzxjAgR6sR7UwjEjsTWNsYrkltt70w9IR/2x92+aN0AKxBMv0znuxoXogZQSgKQY8VBgrsiaisCcXUaqpFtFc/fI+80hrFOYY/Ny8efPc7TGUr+t8lEuTi7BG+dBbCkDjCUKxJheZTzQ4oQD0J9Le6BlD9+o67+WSBdJ85Q+vqfmOtGjsl/dhkSXRoVmgN9oGmaGv6/wuBwG+TQSO91oDAG3KB9aaMkCeC8fxef3pQi4BjA5B/dIbgQeSwcMSvQ/bAwPEz5nV9Zf4BtD3cwkgFqi05kWsy+bDBJHNZrWZCYEAEiC8w1v+ZDegnsk1gLLA52wGViLyTrj0zk7oFyDWxmRy5vqtWrWq31mo8cR5CjiPpTp+GDZApStPJGqBfnF+vwCt/2pN0JpvCjqUSxaID1Rz/CL+LVYUjieL0jY+aG8yfa6pWuAIQRW5AtB6Ioqwy4IGkXgBhpIAw3zrz1leEr4uptSEL+cCwGgS/U5DQ4ODqHQYspcR3SGmsBV9Xf8ksx2S9YVhAORc5gOqyX2NN9jDeHvdK6wwlO8i9PedBJX3C8T72bTA6CDEdTXdUdazCFvO6NGj06IRI0bw2lcj036TscIwAPKKl5rZNt4XNqcfOkBe20qHCgoK3PQoEomcAkiiEFMBaE1XkffxNWvWuL6Kgdh0KKkXkYPIPtbAvy+QLyQ6OpMsQI5nCq/KH2Ah9rZ6WMHDr743dtIh/n3eCmKAoaqq6jfpBug59pIqN4gKApAAki6F8nmTgWTfoSktLZ0iS7wR1BITBWgj1z09PbcEbiZvT/Htm3QaCHItJN3ifbToK7OrFZ0D+cNEAZIs8/xYPYY68j2sw3K/dModrsqEyA0ZW9Ty6SBWmChA/J7yvSdra2v7Et1MyBk2bFjGlJeX54wZM2aImtfvwwLo+dDOFfnc4Vg7vjdTypgFoqgF4hMj8V7MScQCSVlaW1sbGARN5MscYcj9xkEmNX36dPfLRgL0FB+mSAUg+06cONHb3Nz8bHFxsTuqRO6ZSTnjxo3LuEaNGuWOfCuonI/lD4MAJGh0d3dfJBrOnDnTnduYaTkTJ07MuPioGc2ZfrNSnbP9QRwIIAOkwJPfu7hu3brBpCtEXXK+TCtrAPGFPCqNzpU5Jn/4qcHDN/L1Nv/0Nu/n79RNO8kApwC6zpwyG8oqQPsSSHRu4YOCd1zLrwncFVngn1W+Jyv7iyzuhsr329vbf6Jg8dWWlpZ8m65GLgZAPpaTDf0HAAD//wn6X9IAAAAGSURBVAMA1bR60Da8N6EAAAAASUVORK5CYII=" class="logo"></img>
            <div>
                <a href="/settings" class="btn">Settings</a>
                <a href="/web_serial" class="btn">Web Serial</a>
                <a href="/OTA" class="btn">OTA Update</a>
            </div>
        </div>

        <div class="module-list">
            <div class="config-warning" id="modulesWarning">
                <div class="warning-icon">⚠️</div>
                <div>
                    <div class="warning-title">Modules Not Configured</div>
                    <div class="warning-text">nRF24 radio modules are not configured. Please set up module pins before using jammers</div>
                    <a href="/settings" class="warning-btn">Configure nRF24 Modules</a>
                </div>
            </div>

            <div class="module-item" onclick="location.href='/bluetooth_jam'">
                <div class="module-info">
                    <div class="module-name">Bluetooth Jammer</div>
                    <div class="module-desc">Jams all Bluetooth devices in range</div>
                </div>
                <div class="module-channels">[||]EdItAbLe TeXt[||]</div>
            </div>

            <div class="module-item" onclick="location.href='/drone_jam'">
                <div class="module-info">
                    <div class="module-name">Drone Jammer</div>
                    <div class="module-desc">Full-spectrum jammer (0-125 channels)</div>
                </div>
                <div class="module-channels">125 channels</div>
            </div>

            <div class="module-item" onclick="showView('view-wifi-main')">
                <div class="module-info">
                    <div class="module-name">WiFi Attack</div>
                    <div class="module-desc">Jam all or specific wifi channels on 2.4 GHz</div>
                </div>
                <div class="module-channels">13 channels</div>
            </div>

            <div class="module-item" onclick="showView('view-ble')">
                <div class="module-info">
                    <div class="module-name">BLE Jammer</div>
                    <div class="module-desc">Jams Bluetooth Low Energy devices</div>
                </div>
                <div class="module-channels">40 channels</div>
            </div>

            <div class="module-item" onclick="location.href='/zigbee_jam'">
                <div class="module-info">
                    <div class="module-name">Zigbee Jammer</div>
                    <div class="module-desc">Jams Zigbee protocol devices</div>
                </div>
                <div class="module-channels">16 channels</div>
            </div>

            <div class="module-item" onclick="showView('view-misc')">
                <div class="module-info">
                    <div class="module-name">Misc Jammer</div>
                    <div class="module-desc">Custom channel range (0-125)</div>
                </div>
                <div class="module-channels">0-125 range</div>
            </div>
        </div>
    </div>

    <div id="view-ble" class="view">
        <div class="sub-container">
            <div class="sub-header">
                <h1>BLE Jamming Mode</h1>
            </div>
            
            <div>
                <button class="btn-large" onclick="location.href='/ble_advertising_jam'">
                    <div class="method-info">
                        <div class="method-name">Jam Advertising Channels</div>
                        <div class="method-desc">Interfere with the three primary BLE advertising channels</div>
                    </div>
                </button>
                <button class="btn-large" onclick="location.href='/ble_data_jam'">
                    <div class="method-info">
                        <div class="method-name">Jam Data Channels</div>
                        <div class="method-desc">Interfere with all BLE data transmission channels</div>
                    </div>
                </button>
            </div>
            
            <button class="back-btn" onclick="showView('view-main')">← Back to Main Menu</button>
        </div>
    </div>

    <div id="view-misc" class="view">
        <div class="sub-container">
            <div class="sub-header">
                <h1>Custom Channel Range</h1>
            </div>

            <div class="input-group">
                <div class="input-row">
                    <div class="input-wrapper">
                        <label class="label" for="startInput">Start Channel</label>
                        <input id="startInput" class="input" type="number" placeholder="0" max="125" min="0" />
                    </div>

                    <div class="input-wrapper">
                        <label class="label" for="stopInput">Stop Channel</label>
                        <input id="stopInput" class="input" type="number" placeholder="125" max="125" min="0" />
                    </div>
                </div>
            </div>

            <div>
                <button class="btn-large action" onclick="validateAndRedirectMisc()">Start Jamming</button>
                <button class="back-btn" onclick="showView('view-main')">← Back to Main Menu</button>
            </div>
        </div>
    </div>

    <div id="view-wifi-main" class="view">
        <div class="sub-container">
            <div class="sub-header">
                <h1>WiFi Attack Mode</h1>
            </div>

            <div class="toggle" id="modeToggle">
                <button id="jamBtn" class="toggle-btn active" onclick="switchMode('jam')">Jam</button>
                <button id="deauthBtn" class="toggle-btn" onclick="switchMode('deauth')">Deauth</button>
                <button id="spamBtn" class="toggle-btn" onclick="switchMode('spam')">Spam</button>
            </div>

            <div id="jamOptions" class="options">
                <button class="btn-large" onclick="location.href='/wifi_jam'">
                    <div class="method-info">
                        <div class="method-name">Jam All Channels</div>
                        <div class="method-desc">Interfere with all WiFi frequencies simultaneously</div>
                    </div>
                </button>
                <button class="btn-large" onclick="showView('view-wifi-jam-channel')">
                    <div class="method-info">
                        <div class="method-name">Select Channel To Jam</div>
                        <div class="method-desc">Target specific WiFi channel (1-14)</div>
                    </div>
                </button>
                <button class="btn-large" onclick="location.href='/wifi_scan_jam'">
                    <div class="method-info">
                        <div class="method-name">Smart Jam</div>
                        <div class="method-desc">Scan for active networks and jam only their</div>
                    </div>
                </button>
            </div>

            <div id="deauthOptions" class="options hidden">
                <button class="btn-large" onclick="location.href='/wifi_deauth_all'">
                    <div class="method-info">
                        <div class="method-name">Deauth All Channels</div>
                        <div class="method-desc">Disconnect all WiFi clients from every AP</div>
                    </div>
                </button>
                <button class="btn-large" onclick="showView('view-wifi-deauth-channel')">
                    <div class="method-info">
                        <div class="method-name">Select Channel To Deauth</div>
                        <div class="method-desc">Target specific WiFi channel (1-14)</div>
                    </div>
                </button>
                <button class="btn-large" onclick="location.href='/wifi_deauth_scan'">
                    <div class="method-info">
                        <div class="method-name">Smart Deauth</div>
                        <div class="method-desc">Scan for active channels and deauth only their</div>
                    </div>
                </button>
            </div>

            <div id="spamOptions" class="options hidden">
                <button class="btn-large" onclick="location.href='/wifi_random_spam'">
                    <div class="method-info">
                        <div class="method-name">Random Beacon Spam</div>
                        <div class="method-desc">Spam with randomly generated SSIDs</div>
                    </div>
                </button>
                <button class="btn-large" onclick="location.href='/wifi_array_spam'">
                    <div class="method-info">
                        <div class="method-name">Array Beacon Spam</div>
                        <div class="method-desc">Spam using SSIDs from the predefined list in settings</div>
                    </div>
                </button>
            </div>
            
            <button class="back-btn" onclick="showView('view-main')">← Back to Main Menu</button>
        </div>
    </div>

    <div id="view-wifi-jam-channel" class="view">
        <div class="sub-container">
            <div class="sub-header">
                <h1>Select WiFi Channel</h1>
            </div>

            <div class="input-group">
                <label class="label" for="channelInput">Channel Number (1-14)</label>
                <input id="channelInput_Jam" class="input" type="number" placeholder="Enter channel number" max="14" min="1" />
                <div class="channel-display-container">
                    <div id="channelDisplay_Jam" class="channel-display"></div>
                    <button id="rescanBtn_Jam" class="rescan-btn" onclick="showUpdateConfirm()">Rescan</button>
                </div>
                <div id="ssidListContainer_Jam" style="display: none;">
                    <label class="label">Access Points on this channel:</label>
                    <div id="ssidList_Jam"></div>
                </div>
            </div>

            <div>
                <button class="btn-large action" onclick="validateAndRedirectWifiJam()">Start Attack</button>
                <button class="back-btn" onclick="showView('view-wifi-main')">← Back to WiFi Selection</button>
            </div>
        </div>
    </div>

    <div id="view-wifi-deauth-channel" class="view">
        <div class="sub-container">
            <div class="sub-header">
                <h1>Select WiFi Channel</h1>
            </div>

            <div class="input-group">
                <label class="label" for="channelInput">Channel Number (1-14)</label>
                <input id="channelInput_Deauth" class="input" type="number" placeholder="Enter channel number" max="14" min="1" />
                <div class="channel-display-container">
                    <div id="channelDisplay_Deauth" class="channel-display"></div>
                    <button id="rescanBtn_Deauth" class="rescan-btn" onclick="showUpdateConfirm()">Rescan</button>
                </div>
                <div id="ssidListContainer_Deauth" style="display: none;">
                    <label class="label">Access Points on this channel:</label>
                    <div id="ssidList_Deauth"></div>
                </div>
            </div>

            <div>
                <button class="btn-large action" onclick="validateAndRedirectWifiDeauth()">Start Attack</button>
                <button class="back-btn" onclick="showView('view-wifi-main')">← Back to WiFi Selection</button>
            </div>
        </div>
    </div>

    <script>
        function showView(viewId) {
            document.querySelectorAll('.view').forEach(v => v.classList.remove('active'));
            document.getElementById(viewId).classList.add('active');
        }

        if (false) { //IsModulesConfigured
            document.getElementById('modulesWarning').style.display = 'flex';
            document.querySelectorAll('.module-item').forEach(item => {
                item.classList.add('disabled');
                item.onclick = () => alert('Please configure nRF24 modules first. Go to Settings → nRF24');
            });
        }

        function showNotification(message, isSuccess = false) {
            const notification = document.getElementById("notification");
            notification.textContent = message;
            notification.className = isSuccess ? "notification success" : "notification error";
            notification.style.display = "block";

            setTimeout(() => {
                notification.style.top = "20px";
            }, 10);

            setTimeout(() => {
                notification.style.top = "-100px";
                setTimeout(() => {
                    notification.style.display = "none";
                }, 500);
            }, 3000);
        }

        function validateAndRedirectMisc() {
            const startInput = document.getElementById('startInput');
            const stopInput = document.getElementById('stopInput');
            const startValue = parseInt(startInput.value);
            const stopValue = parseInt(stopInput.value);
            let hasError = false;

            startInput.classList.remove('invalid');
            stopInput.classList.remove('invalid');

            if (isNaN(startValue) || startValue < 0 || startValue > 125) {
                showNotification('Start channel must be a number between 0 and 125.');
                startInput.classList.add('invalid');
                hasError = true;
            }
            
            if (isNaN(stopValue) || stopValue < 0 || stopValue > 125) {
                showNotification('Stop channel must be a number between 0 and 125.');
                stopInput.classList.add('invalid');
                hasError = true;
            }
            
            if (!hasError && stopValue < startValue) {
                showNotification('Stop channel must be greater than or equal to start channel.');
                startInput.classList.add('invalid');
                stopInput.classList.add('invalid');
                hasError = true;
            }

            if (!hasError) {
                location.href = `/misc_jam?start=${startValue}&stop=${stopValue}`;
            }
        }

        function switchMode(mode) {
            const jamBtn = document.getElementById('jamBtn');
            const deauthBtn = document.getElementById('deauthBtn');
            const spamBtn = document.getElementById('spamBtn');
            const jamOptions = document.getElementById('jamOptions');
            const deauthOptions = document.getElementById('deauthOptions');
            const spamOptions = document.getElementById('spamOptions');

            if (mode === 'jam') {
                jamBtn.classList.add('active');
                deauthBtn.classList.remove('active');
                spamBtn.classList.remove('active');
                
                deauthOptions.classList.add('hidden');
                spamOptions.classList.add('hidden');
                jamOptions.classList.remove('hidden');
            } else if (mode === 'deauth') {
                deauthBtn.classList.add('active');
                jamBtn.classList.remove('active');
                spamBtn.classList.remove('active');
                
                jamOptions.classList.add('hidden');
                spamOptions.classList.add('hidden');
                deauthOptions.classList.remove('hidden');
            } else {
                spamBtn.classList.add('active');
                deauthBtn.classList.remove('active');
                jamBtn.classList.remove('active');

                jamOptions.classList.add('hidden');
                deauthOptions.classList.add('hidden');
                spamOptions.classList.remove('hidden');
            }
        }

        let ch1 = 0;
        let ch2 = 0;
        let ch3 = 0;
        let ch4 = 0;
        let ch5 = 0;
        let ch6 = 0;
        let ch7 = 0;
        let ch8 = 0;
        let ch9 = 0;
        let ch10 = 0;
        let ch11 = 0;
        let ch12 = 0;
        let ch13 = 0;
        let ch14 = 0;
		
        let ssidsByChannel = [];
        
        let actionCallback = null;

        function showConfirmDialog(title, message, callback) {
            document.getElementById('confirmTitle').textContent = title;
            document.getElementById('confirmMessage').textContent = message;
            document.getElementById('overlay').style.display = 'block';
            document.getElementById('confirmDialog').style.display = 'block';
            actionCallback = callback;
        }
        
        function hideConfirmDialog() {
            document.getElementById('overlay').style.display = 'none';
            document.getElementById('confirmDialog').style.display = 'none';
            actionCallback = null;
        }
        
        function confirmAction() {
            if (actionCallback) actionCallback();
            hideConfirmDialog();
        }
        
        function showUpdateConfirm() {
            showConfirmDialog(
                "Rescan Wi-Fi APs",
                "During the scanning process, the device will temporarily disconnect from the access point. Do you want to continue?",
                startUpdateScan
            );
        }
        
        function startUpdateScan() {
            showNotification("Starting WiFi scan... The device will temporarily disconnect.", true);
            setTimeout(() => location.href = "/rescan", 1000);
        }

        function escapeHtml(unsafe) {
            return unsafe.replace(/[&<>"]/g, function(m) {
                if (m === '&') return '&amp;';
                if (m === '<') return '&lt;';
                if (m === '>') return '&gt;';
                if (m === '"') return '&quot;';
                return m;
            });
        }

        function getChannelValue(channel) {
            switch(channel) {
                case 1: return ch1; case 2: return ch2; case 3: return ch3;
                case 4: return ch4; case 5: return ch5; case 6: return ch6;
                case 7: return ch7; case 8: return ch8; case 9: return ch9;
                case 10: return ch10; case 11: return ch11; case 12: return ch12;
                case 13: return ch13; case 14: return ch14; default: return 0;
            }
        }

        function updateChannelDisplay(channel, suffix) {
            const display = document.getElementById('channelDisplay_' + suffix);
            const rescanBtn = document.getElementById('rescanBtn_' + suffix);
            const ssidContainer = document.getElementById('ssidListContainer_' + suffix);
            const ssidList = document.getElementById('ssidList_' + suffix);

            const channelValue = getChannelValue(channel);
            display.innerHTML = `Channel ${channel} : ${channelValue} WiFi APs`;
            display.style.display = 'block';
            rescanBtn.style.display = 'block';

            if (ssidsByChannel && ssidsByChannel[channel-1]) {
                const ssids = ssidsByChannel[channel-1];
                if (ssids.trim() !== '') {
                    const lines = ssids.split('\n').filter(s => s.trim() !== '');
                    if (lines.length > 0) {
                        ssidList.innerHTML = lines.map(ssid => `<div>${escapeHtml(ssid)}</div>`).join('');
                        ssidContainer.style.display = 'block';
                        return;
                    }
                }
            }
            ssidContainer.style.display = 'none';
        }

        function validateAndRedirectWifiJam() {
            const channelInput = document.getElementById('channelInput_Jam');
            const channelValue = parseInt(channelInput.value);

            channelInput.classList.remove('invalid');

            if (isNaN(channelValue) || channelValue < 1 || channelValue > 14) {
                showNotification('WiFi channel must be a number between 1 and 14.', false);
                channelInput.classList.add('invalid');
                return;
            }
            
            location.href = `/wifi_selected_jam?channel=${channelValue}`;
        }

        function validateAndRedirectWifiDeauth() {
            const channelInput = document.getElementById('channelInput_Deauth');
            const channelValue = parseInt(channelInput.value);

            channelInput.classList.remove('invalid');

            if (isNaN(channelValue) || channelValue < 1 || channelValue > 14) {
                showNotification('WiFi channel must be a number between 1 and 14.', false);
                channelInput.classList.add('invalid');
                return;
            }
            
            location.href = `/wifi_selected_deauth?channel=${channelValue}`;
        }

        document.getElementById('channelInput_Jam').addEventListener('input', function(e) {
            const channelValue = parseInt(this.value);
            if (!isNaN(channelValue) && channelValue >= 1 && channelValue <= 14) {
                updateChannelDisplay(channelValue, 'Jam');
            } else {
                document.getElementById('channelDisplay_Jam').style.display = 'none';
                document.getElementById('rescanBtn_Jam').style.display = 'none';
                document.getElementById('ssidListContainer_Jam').style.display = 'none';
            }
        });

        document.getElementById('channelInput_Deauth').addEventListener('input', function(e) {
            const channelValue = parseInt(this.value);
            if (!isNaN(channelValue) && channelValue >= 1 && channelValue <= 14) {
                updateChannelDisplay(channelValue, 'Deauth');
            } else {
                document.getElementById('channelDisplay_Deauth').style.display = 'none';
                document.getElementById('rescanBtn_Deauth').style.display = 'none';
                document.getElementById('ssidListContainer_Deauth').style.display = 'none';
            }
        });

        window.addEventListener('load', function() {
            const input = document.getElementById('channelInput_Jam');
            if (input.value) {
                const val = parseInt(input.value);
                if (!isNaN(val) && val >= 1 && val <= 14) {
                    updateChannelDisplay(val, 'Jam');
                }
            }
        });

        window.addEventListener('load', function() {
            const input = document.getElementById('channelInput_Deauth');
            if (input.value) {
                const val = parseInt(input.value);
                if (!isNaN(val) && val >= 1 && val <= 14) {
                    updateChannelDisplay(val, 'Deauth');
                }
            }
        });

        document.addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                if (document.getElementById('view-misc').classList.contains('active')) validateAndRedirectMisc();
                if (document.getElementById('view-wifi-jam-channel').classList.contains('active')) validateAndRedirectWifiJam();
                if (document.getElementById('view-wifi-deauth-channel').classList.contains('active')) validateAndRedirectWifiDeauth();
            }
        });
    </script>
</body>
</html>
)rawliteral";

static const char *const html_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
        }
        
        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            overflow: hidden;
            opacity: 0;
            animation: fadeIn 0.6s ease-out forwards;
        }
        
        @keyframes fadeIn {
            to { opacity: 1; }
        }
        
        #textElement {
            position: absolute;
            font-size: 28px;
            color: var(--accent);
            padding: 30px;
            white-space: nowrap;
            font-weight: 600;
            font-family: 'Arial', sans-serif;
        }
    </style>
</head>
<body>
    <div id="textElement">[||]EdItAbLe TeXt[||]</div>
    
    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';
        
        let posX = 0;
        let posY = 0;
        let speedX = 2;
        let speedY = 1.5;
        let windowWidth = window.innerWidth;
        let windowHeight = window.innerHeight;
        let elementWidth = textElement.offsetWidth;
        let elementHeight = textElement.offsetHeight;
        
        function updateDimensions() {
            windowWidth = window.innerWidth;
            windowHeight = window.innerHeight;
            elementWidth = textElement.offsetWidth;
            elementHeight = textElement.offsetHeight;
        }
        
        window.addEventListener('resize', updateDimensions);
        
        function moveText() {
            requestAnimationFrame(moveText);
            
            posX += speedX;
            posY += speedY;
            
            if (posX <= 0 || posX >= windowWidth - elementWidth) {
                speedX = -speedX;
            }
            if (posY <= 0 || posY >= windowHeight - elementHeight) {
                speedY = -speedY;
            }
            
            textElement.style.left = posX + 'px';
            textElement.style.top = posY + 'px';
        }
        
        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    textElement.textContent = originalText;
                }, 300);
            }
        }, 800);
        
        function init() {
            updateDimensions();
            posX = Math.random() * (windowWidth - elementWidth);
            posY = Math.random() * (windowHeight - elementHeight);
            moveText();
        }
        
        window.addEventListener('load', init);
    </script>
</body>
</html>
)rawliteral";

static const char *const html_ota = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
            --success: #238636;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
        }
        
        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            opacity: 0;
            animation: fadeIn 0.6s ease-out forwards;
        }
        
        @keyframes fadeIn {
            to {
                opacity: 1;
            }
        }
        
        .container {
            width: 100%;
            max-width: 500px;
            padding: 30px;
            border-radius: 12px;
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
            display: flex;
            flex-direction: column;
            gap: 20px;
            position: relative;
        }
        
        .version-badge {
            position: absolute;
            top: 15px;
            right: 15px;
            font-size: 12px;
            color: var(--text-secondary);
            background-color: var(--bg-card);
            padding: 6px 12px;
            border-radius: 20px;
            border: 1px solid var(--border);
            font-weight: 500;
            transition: all 0.3s ease;
        }
        
        .version-badge:hover {
            color: var(--text-primary);
            background-color: var(--border);
            transform: scale(1.05);
        }
        
        .header {
            text-align: center;
        }
        
        .btn {
            background: var(--bg-card);
            border: 1px solid var(--accent);
            color: var(--text-primary);
            padding: 16px 24px;
            border-radius: 8px;
            font-size: 15px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-decoration: none;
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 8px;
            width: 100%;
        }
        
        .btn:hover {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-2px);
            box-shadow: 0 8px 20px rgba(88, 166, 255, 0.2);
        }
        
        .file-upload-container {
            position: relative;
            margin: 20px 0;
            width: 100%;
        }
        
        .file-selection-wrapper {
            display: flex;
            gap: 12px;
            align-items: stretch;
        }
        
        .file-info-display {
            flex: 1;
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 8px;
            padding: 14px 16px;
            font-size: 14px;
            color: var(--text-secondary);
            display: flex;
            align-items: center;
            min-height: 50px;
            overflow: hidden;
        }
        
        .file-info-display.has-file {
            color: var(--text-primary);
        }
        
        .file-info-display::before {
            content: "📁";
            font-size: 16px;
            margin-right: 10px;
            opacity: 0.7;
        }
        
        .file-info-display.has-file::before {
            opacity: 1;
        }
        
        .file-select-btn {
            background: var(--bg-card);
            color: var(--text-primary);
            padding: 14px 24px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            display: flex;
            align-items: center;
            justify-content: center;
            white-space: nowrap;
            min-width: 120px;
        }
        
        .file-select-btn:hover {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-2px);
            box-shadow: 0 8px 20px rgba(88, 166, 255, 0.2);
        }
        
        .file-upload-container input[type="file"] {
            display: none;
        }
        
        .warning {
            margin-top: 16px;
            padding: 12px;
            background: rgba(240, 136, 62, 0.1);
            border: 1px solid #f0883e;
            border-radius: 8px;
            color: #f0883e;
            font-size: 13px;
            text-align: center;
        }
        
        .upload-form {
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 16px;
        }
        
        .back-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 24px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-decoration: none;
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 8px;
            width: 100%;
        }
        
        .back-btn:hover {
            background: var(--bg-secondary);
            border-color: var(--accent);
            transform: translateY(-2px);
        }
        
        .form-group {
            width: 100%;
            display: flex;
            flex-direction: column;
            gap: 16px;
        }
        
        .progress-container {
            width: 100%;
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 8px;
            padding: 4px;
            margin-top: 10px;
            display: block;
        }
        
        .progress-bar {
            height: 8px;
            background: var(--accent);
            border-radius: 4px;
            width: 0%;
            transition: width 0.3s ease;
        }
        
        .progress-text {
            font-size: 12px;
            color: var(--text-secondary);
            text-align: center;
            margin-top: 5px;
        }
        
        .no-file-text {
            opacity: 0.7;
            font-style: italic;
        }
    </style>
</head>

<body>
    <div class="container">
        <div class="version-badge">version</div>

        <div class="header">
            <h2>Firmware Update</h2>
        </div>

        <div class="progress-container" id="progressContainer">
            <div class="progress-bar" id="progressBar"></div>
            <div class="progress-text" id="progressText">0%</div>
        </div>

        <form enctype='multipart/form-data' action='/update' method='POST' class="upload-form" id="uploadForm">
            <div class="file-upload-container">
                <div class="file-selection-wrapper">
                    <div class="file-info-display" id="fileInfoDisplay">
                        <span class="no-file-text">No file selected</span>
                    </div>
                    <label for="file-upload" class="file-select-btn">Select File</label>
                    <input type='file' id="file-upload" name='update' accept=".bin" required>
                </div>
            </div>

            <div class="form-group">
                <button class="btn" type="submit" id="uploadBtn">Update Firmware</button>
                <button class="back-btn" type="button" onclick="location.href='/'">← Back to Main Menu</button>
            </div>

            <div class="warning">⚠️ Do not select bootloader or partition files!</div>
        </form>
    </div>

    <script>
        const fileInput = document.getElementById('file-upload');
        const fileInfoDisplay = document.getElementById('fileInfoDisplay');
        const progressContainer = document.getElementById('progressContainer');
        const progressBar = document.getElementById('progressBar');
        const progressText = document.getElementById('progressText');
        const uploadForm = document.getElementById('uploadForm');
        const uploadBtn = document.getElementById('uploadBtn');

        fileInput.addEventListener('change', function(e) {
            if (this.files && this.files[0]) {
                const file = this.files[0];
                fileInfoDisplay.innerHTML = `<span>Selected: <strong>${file.name}</strong> (${(file.size / 1024 / 1024).toFixed(2)} MB)</span>`;
                fileInfoDisplay.classList.add('has-file');
            } else {
                fileInfoDisplay.innerHTML = '<span class="no-file-text">No file selected</span>';
                fileInfoDisplay.classList.remove('has-file');
            }
        });

        uploadForm.addEventListener('submit', function(e) {
            e.preventDefault();

            const formData = new FormData(this);
            const xhr = new XMLHttpRequest();

            xhr.upload.addEventListener('progress', function(event) {
                if (event.lengthComputable) {
                    const percentComplete = (event.loaded / event.total) * 100;
                    progressBar.style.width = percentComplete + '%';
                    progressText.textContent = Math.round(percentComplete) + '%';

                    if (!progressContainer.style.display || progressContainer.style.display === 'none') {
                        progressContainer.style.display = 'block';
                    }
                }
            });

            xhr.addEventListener('load', function() {
                if (xhr.status === 200) {
                    progressText.textContent = 'Upload complete! Updating...';
                    setTimeout(() => {
                        progressText.textContent = 'Update successful! Device is restarting...';
                    }, 1000);
                } else {
                    progressText.textContent = 'Upload failed - server error';
                    progressBar.style.background = '#f85149';
                    uploadBtn.disabled = false;
                }
            });

            xhr.addEventListener('error', function() {
                progressText.textContent = 'Upload failed - connection error';
                progressBar.style.background = '#f85149';
                uploadBtn.disabled = false;
            });

            xhr.open('POST', '/update');
            xhr.send(formData);
            uploadBtn.disabled = true;
        });
    </script>
</body>
</html>
)rawliteral";

static const char *const html_pls_reboot = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
        }
        
        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            opacity: 0;
            animation: fadeIn 0.6s ease-out forwards;
        }
        
        @keyframes fadeIn {
            to { opacity: 1; }
        }
        
        .container {
            width: 100%;
            max-width: 450px;
            padding: 30px;
            border-radius: 12px;
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 30px;
        }
        
        .message {
            font-size: 28px;
            font-weight: 600;
            color: var(--accent);
            text-align: center;
            padding: 30px;
            border-radius: 12px;
            background: rgba(88, 166, 255, 0.1);
            border: 1px solid rgba(88, 166, 255, 0.2);
            width: 100%;
            position: relative;
            overflow: hidden;
        }
        
        .loading {
            display: flex;
            gap: 16px;
        }
        
        .dot {
            width: 16px;
            height: 16px;
            border-radius: 50%;
            background: var(--accent);
            animation: pulse 1.4s infinite ease-in-out;
        }
        
        .dot:nth-child(1) { animation-delay: -0.32s; }
        .dot:nth-child(2) { animation-delay: -0.16s; }
        .dot:nth-child(3) { animation-delay: 0s; }
        
        @keyframes pulse {
            0%, 80%, 100% { transform: scale(0.8); opacity: 0.5; }
            40% { transform: scale(1.2); opacity: 1; }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="message">
            Please reboot
        </div>
        
        <div class="loading">
            <div class="dot"></div>
            <div class="dot"></div>
            <div class="dot"></div>
        </div>
    </div>
</body>
</html>
)rawliteral";

static const char *const html_settings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Device Configuration</title>
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
            --danger: #f85149;
            --warning: #f0883e;
            --success: #2ea043;
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
        }

        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            padding: 20px;
            opacity: 0;
            animation: fadeIn 0.6s ease-out forwards;
        }

        @keyframes fadeIn {
            to { opacity: 1; }
        }

        .container {
            width: 100%;
            max-width: 600px;
            padding: 30px;
            border-radius: 12px;
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
            display: flex;
            flex-direction: column;
            gap: 20px;
        }

        .header {
            text-align: center;
            margin-bottom: 5px;
        }

        .header h1 {
            font-size: clamp(1.5rem, 4vw, 2rem);
        }

        .tabs {
            display: flex;
            gap: 10px;
            width: 100%;
        }

        .tab-btn {
            flex: 1;
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-secondary);
            padding: 12px 5px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-align: center;
        }

        .tab-btn:hover {
            background: var(--bg-secondary);
            border-color: var(--accent);
            color: var(--text-primary);
            transform: translateY(-2px);
        }

        .tab-btn.active {
            background: rgba(88, 166, 255, 0.1);
            border-color: var(--accent);
            color: var(--accent);
        }

        .tab-content {
            display: none;
            animation: slideIn 0.4s cubic-bezier(0.4, 0, 0.2, 1) forwards;
        }

        .tab-content.active {
            display: flex;
            flex-direction: column;
            gap: 16px;
        }

        .section-title {
            font-size: 16px;
            font-weight: 600;
            color: var(--text-primary);
            margin-bottom: -4px;
        }

        .options-group {
            display: flex;
            flex-direction: column;
            gap: 12px;
        }

        .option-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 16px 24px;
            border-radius: 8px;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            display: flex;
            align-items: center;
            justify-content: space-between;
            width: 100%;
            text-align: left;
        }

        .option-btn:hover {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-2px);
            box-shadow: 0 8px 20px rgba(88, 166, 255, 0.2);
        }

        .option-btn.active {
            border-color: var(--success);
        }

        .option-btn.active:hover {
            background: var(--success);
            border-color: var(--success);
            box-shadow: 0 8px 20px rgba(46, 160, 67, 0.2);
        }

        .method-info { text-align: left; }
        .method-name { font-size: 16px; font-weight: 600; margin-bottom: 4px; color: var(--text-primary); }
        .method-desc { font-size: 13px; color: var(--text-secondary); transition: color 0.2s; }
        
        .option-btn:hover .method-desc, 
        .option-btn.active:hover .method-desc {
            color: rgba(255, 255, 255, 0.8);
        }

        .modules-container {
            max-height: 300px;
            overflow-y: auto;
            padding-right: 5px;
        }
        
        .modules-container::-webkit-scrollbar { width: 6px; }
        .modules-container::-webkit-scrollbar-track { background: var(--bg-card); border-radius: 3px; }
        .modules-container::-webkit-scrollbar-thumb { background: var(--border); border-radius: 3px; }

        .input-group {
            display: flex;
            align-items: flex-start;
            gap: 12px;
            margin-bottom: 12px;
            width: 100%;
            animation: slideIn 0.4s cubic-bezier(0.4, 0, 0.2, 1) forwards;
        }

        @keyframes slideIn {
            from { opacity: 0; transform: translateX(-10px); }
            to { opacity: 1; transform: translateX(0); }
        }

        .input-wrapper { flex: 1; display: flex; flex-direction: column; gap: 4px; }
        .input-label { font-size: 12px; color: var(--text-secondary); font-weight: 500; height: 16px; line-height: 16px; }
        
        .input {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 16px;
            border-radius: 8px;
            font-size: 14px;
            transition: all 0.2s;
            width: 100%;
            height: 48px;
        }

        .input:disabled {
            background: var(--bg-primary);
            opacity: 0.5;
            cursor: not-allowed;
            border-color: var(--border);
        }

        .text-center { text-align: center; }

        .input:focus {
            outline: none;
            border-color: var(--accent);
            box-shadow: 0 0 0 2px rgba(88, 166, 255, 0.2);
        }

        .checkbox-wrapper {
            display: inline-flex;
            align-items: center;
            gap: 10px;
            margin-bottom: 12px;
            cursor: pointer;
            user-select: none;
            width: fit-content;
        }

        .checkbox-wrapper input {
            display: none;
        }

        .checkmark {
            width: 20px;
            height: 20px;
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 6px;
            display: flex;
            align-items: center;
            justify-content: center;
            transition: all 0.2s ease;
            flex-shrink: 0;
        }

        .checkbox-wrapper:hover .checkmark {
            border-color: var(--accent);
        }

        .checkbox-wrapper input:checked + .checkmark {
            background: var(--accent);
            border-color: var(--accent);
        }

        .checkmark::after {
            content: '';
            width: 5px;
            height: 10px;
            border: solid var(--bg-primary);
            border-width: 0 2px 2px 0;
            transform: rotate(45deg) scale(0);
            transition: transform 0.15s ease-in-out;
            margin-bottom: 2px;
        }

        .checkbox-wrapper input:checked + .checkmark::after {
            transform: rotate(45deg) scale(1);
        }

        .checkbox-label {
            font-size: 14px;
            font-weight: 500;
            color: var(--text-primary);
        }

        .btn-add {
            background: var(--bg-card);
            border: 1px solid var(--success);
            color: white;
            font-size: 15px;
            padding: 16px 24px;
            height: 48px;
            border-radius: 8px;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            width: 100%;
            display: flex;
            align-items: center;
            justify-content: center;
            font-weight: 500;
        }

        .btn-add:hover {
            background: var(--success);
            border-color: var(--success);
            box-shadow: 0 8px 20px rgba(46, 160, 67, 0.2);
            transform: translateY(-2px);
        }

        .delete-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-secondary);
            width: 48px; height: 48px;
            border-radius: 8px;
            display: flex; align-items: center; justify-content: center;
            cursor: pointer; transition: all 0.25s; flex-shrink: 0; font-size: 20px;
            margin-top: 16px;
        }

        .delete-btn:not(:disabled) { border-color: var(--danger); color: var(--danger); }
        .delete-btn:not(:disabled):hover {
            background: var(--danger); border-color: var(--danger); color: white;
            transform: translateY(-2px); box-shadow: 0 8px 20px rgba(248, 81, 73, 0.2);
        }
        .delete-btn:disabled { opacity: 0.3; cursor: not-allowed; }

        .controls {
            display: flex;
            flex-direction: column;
            gap: 12px;
            margin-top: 10px;
            padding-top: 20px;
            border-top: 1px solid var(--border);
        }

        .back-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 16px 24px;
            border-radius: 8px;
            font-size: 14px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-decoration: none;
            display: flex;
            align-items: center;
            justify-content: center;
            width: 100%;
            height: 48px;
        }

        .back-btn:hover {
            background: var(--bg-secondary);
            border-color: var(--accent);
            transform: translateY(-2px);
        }

        .notification {
            position: fixed; top: -100px; left: 50%; transform: translateX(-50%);
            padding: 14px 24px; border-radius: 0 0 8px 8px;
            color: white; font-weight: 500; z-index: 1000;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.2);
            transition: top 0.5s ease-out;
            width: 90%; max-width: 400px; text-align: center;
            display: none;
        }
        .notification.error { background: linear-gradient(135deg, var(--danger), #da3633); }
        .notification.success { background: linear-gradient(135deg, var(--success), #288b3b); }
    </style>
</head>
<body>
    <div id="notification" class="notification"></div>

    <div class="container">
        <div class="header">
            <h1>Settings</h1>
        </div>

        <div class="tabs">
            <button class="tab-btn active" onclick="switchTab('tab-general')">General</button>
            <button class="tab-btn" onclick="switchTab('tab-nrf')">nRF24</button>
            <button class="tab-btn" onclick="switchTab('tab-jam')">Jammer</button>
            <button class="tab-btn" onclick="switchTab('tab-attacks')">Attacks</button>
        </div>

        <div id="tab-general" class="tab-content active">
            <div class="section-title">Logo Settings</div>
            <div class="options-group">
                <button class="option-btn opt-logo active" onclick="setOpt('logo', 0)">
                    <div class="method-info">
                        <div class="method-name">Show logo</div>
                        <div class="method-desc">Display logo when device boots</div>
                    </div>
                </button>
                <button class="option-btn opt-logo" onclick="setOpt('logo', 1)">
                    <div class="method-info">
                        <div class="method-name">Hide logo</div>
                        <div class="method-desc">Skip logo display on boot</div>
                    </div>
                </button>
            </div>

            <div class="section-title">Display Control</div>
            <div class="options-group">
                <button class="option-btn opt-display active" onclick="setOpt('display', 0)">
                    <div class="method-info">
                        <div class="method-name">Enable Display</div>
                        <div class="method-desc">Turn on display</div>
                    </div>
                </button>
                <button class="option-btn opt-display" onclick="setOpt('display', 1)">
                    <div class="method-info">
                        <div class="method-name">Disable Display</div>
                        <div class="method-desc">Turn off display</div>
                    </div>
                </button>
            </div>

            <div class="section-title">Button Configuration</div>
            <div class="options-group">
                <button class="option-btn opt-button active" onclick="setOpt('button', 0)">
                    <div class="method-info">
                        <div class="method-name">1 Button</div>
                        <div class="method-desc">Pin 25 only</div>
                    </div>
                </button>
                <button class="option-btn opt-button" onclick="setOpt('button', 1)">
                    <div class="method-info">
                        <div class="method-name">2 Buttons</div>
                        <div class="method-desc">Pins 25, 26</div>
                    </div>
                </button>
                <button class="option-btn opt-button" onclick="setOpt('button', 2)">
                    <div class="method-info">
                        <div class="method-name">3 Buttons</div>
                        <div class="method-desc">Pins 25, 26, 27</div>
                    </div>
                </button>
            </div>

            <div class="section-title" style="margin-top: 5px;">WiFi Settings</div>
            
            <label class="checkbox-wrapper">
                <input type="checkbox" id="ap-disable" onchange="toggleApStatus()">
                <div class="checkmark"></div>
                <span class="checkbox-label">Disable AP</span>
            </label>

            <div class="input-group" style="margin-bottom: 0;">
                <div class="input-wrapper">
                    <input type="text" id="wifi-ssid" class="input" placeholder="Network SSID">
                </div>
            </div>
            <div class="input-group">
                <div class="input-wrapper">
                    <input type="text" id="wifi-pass" class="input" placeholder="Password">
                </div>
            </div>
        </div>

        <div id="tab-nrf" class="tab-content">
            <div class="section-title">Channel Sweep Direction</div>
            <div class="options-group">
                <button class="option-btn opt-sweep active" onclick="setOpt('sweep', 0)">
                    <div class="method-info">
                        <div class="method-name">Opposite Directions</div>
                        <div class="method-desc">Better coverage</div>
                    </div>
                </button>
                <button class="option-btn opt-sweep" onclick="setOpt('sweep', 1)">
                    <div class="method-info">
                        <div class="method-name">Same Direction</div>
                        <div class="method-desc">Synchronized sweep</div>
                    </div>
                </button>
            </div>

            <div class="section-title">nRF24 PA Level</div>
            <div class="options-group">
                <button class="option-btn opt-pa active" onclick="setOpt('pa', 0)">
                    <div class="method-name">Max</div>
                    <div class="method-desc">0 dBm</div>
                </button>
                <button class="option-btn opt-pa" onclick="setOpt('pa', 1)">
                    <div class="method-name">High</div>
                    <div class="method-desc">-6 dBm</div>
                </button>
                <button class="option-btn opt-pa" onclick="setOpt('pa', 2)">
                    <div class="method-name">Low</div>
                    <div class="method-desc">-12 dBm</div>
                </button>
                <button class="option-btn opt-pa" onclick="setOpt('pa', 3)">
                    <div class="method-name">Min</div>
                    <div class="method-desc">-18 dBm</div>
                </button>
            </div>

            <div class="section-title" style="margin-top: 10px;">nRF24 Modules Setup</div>
            <div id="nrf-container" class="modules-container">
            </div>
            <button class="btn-add" onclick="addNrfModule()">+ Add Module</button>
        </div>

        <div id="tab-jam" class="tab-content">
            <div class="section-title">Bluetooth Jam Method</div>
            <div class="options-group">
                <button class="option-btn opt-bt active" onclick="setOpt('bt', 0)">
                    <div class="method-info"><div class="method-name">Brute Force By List</div><div class="method-desc">21 predefined channels</div></div>
                </button>
                <button class="option-btn opt-bt" onclick="setOpt('bt', 1)">
                    <div class="method-info"><div class="method-name">Randomize</div><div class="method-desc">0-79 channels</div></div>
                </button>
                <button class="option-btn opt-bt" onclick="setOpt('bt', 2)">
                    <div class="method-info"><div class="method-name">Brute Force Scan</div><div class="method-desc">All 80 channels</div></div>
                </button>
            </div>

            <div class="section-title">Drone Jam Method</div>
            <div class="options-group">
                <button class="option-btn opt-drone active" onclick="setOpt('drone', 0)">
                    <div class="method-info"><div class="method-name">Randomize</div><div class="method-desc">0-125 channels</div></div>
                </button>
                <button class="option-btn opt-drone" onclick="setOpt('drone', 1)">
                    <div class="method-info"><div class="method-name">Brute Force Scan</div><div class="method-desc">Systematic scan</div></div>
                </button>
            </div>

            <div class="section-title">Misc Jam Method</div>
            <div class="options-group">
                <button class="option-btn opt-misc active" onclick="setOpt('misc', 0)">
                    <div class="method-info"><div class="method-name">Channel Switching</div><div class="method-desc">Fast mode</div></div>
                </button>
                <button class="option-btn opt-misc" onclick="setOpt('misc', 1)">
                    <div class="method-info"><div class="method-name">Packet Sending</div><div class="method-desc">Slow mode</div></div>
                </button>
            </div>
        </div>

        <div id="tab-attacks" class="tab-content">
            <div class="section-title">WiFi Beacon Spam</div>
            
            <div id="beacon-container" class="modules-container">
            </div>
            
            <button class="btn-add" onclick="addBeaconModule()">+ Add SSID</button>
        </div>

        <div class="controls">
            <button class="btn-add" onclick="saveAllSettings()">Save Settings</button>
            <button class="back-btn" onclick="location.href='/'">← Back to Main Menu</button>
        </div>
    </div>

    <script>
        const state = {
            logo: 0,
            display: 0,
            button: 0,
            sweep: 0,
            pa: 0,
            bt: 0,
            drone: 0,
            misc: 0,
            ap: 0
        };

        function switchTab(tabId) {
            document.querySelectorAll('.tab-btn').forEach(btn => btn.classList.remove('active'));
            document.querySelectorAll('.tab-content').forEach(content => content.classList.remove('active'));
            
            event.target.classList.add('active');
            document.getElementById(tabId).classList.add('active');
        }

        function setOpt(category, value) {
            state[category] = value;
            const buttons = document.querySelectorAll(`.opt-${category}`);
            buttons.forEach(el => el.classList.remove('active'));
            if (buttons[value]) {
                buttons[value].classList.add('active');
            }
        }

        function toggleApStatus() {
            const isChecked = document.getElementById('ap-disable').checked;
            state.ap = isChecked ? 1 : 0;
            document.getElementById('wifi-ssid').disabled = isChecked;
            document.getElementById('wifi-pass').disabled = isChecked;
        }

        function addNrfModule(ce = '', csn = '') {
            const container = document.getElementById('nrf-container');
            if(container.children.length >= 30) {
                showToast("Maximum 30 modules allowed", true);
                return;
            }

            const div = document.createElement('div');
            div.className = 'input-group nrf-module';
            div.innerHTML = `
                <div class="input-wrapper">
                    <label class="input-label">CE Pin</label>
                    <input type="number" class="input text-center ce-pin" value="${ce}" placeholder="CE" min="0" max="99">
                </div>
                <div class="input-wrapper">
                    <label class="input-label">CSN Pin</label>
                    <input type="number" class="input text-center csn-pin" value="${csn}" placeholder="CSN" min="0" max="99">
                </div>
                <button class="delete-btn" onclick="removeNrfModule(this)" title="Remove module"><span>×</span></button>
            `;
            container.appendChild(div);
            updateNrfButtons();
        }

        function removeNrfModule(btn) {
            const group = btn.closest('.nrf-module');
            group.style.opacity = '0';
            group.style.transform = 'translateX(20px)';
            group.style.transition = 'all 0.3s ease';
            setTimeout(() => { group.remove(); updateNrfButtons(); }, 300);
        }

        function updateNrfButtons() {
            const deleteBtns = document.getElementById('nrf-container').querySelectorAll('.delete-btn');
            deleteBtns.forEach(btn => btn.disabled = (deleteBtns.length <= 1));
        }

        function addBeaconModule(ssid = '') {
            const container = document.getElementById('beacon-container');
            if(container.children.length >= 99) {
                showToast("Maximum 99 SSIDs allowed", true);
                return;
            }

            const div = document.createElement('div');
            div.className = 'input-group beacon-module';
            div.innerHTML = `
                <div class="input-wrapper">
                    <label class="input-label">SSID</label>
                    <input type="text" class="input beacon-ssid" value="${ssid}" placeholder="WiFi SSID" maxlength="31">
                </div>
                <button class="delete-btn" onclick="removeBeaconModule(this)" title="Remove SSID"><span>×</span></button>
            `;
            container.appendChild(div);
            updateBeaconButtons();
        }

        function removeBeaconModule(btn) {
            const group = btn.closest('.beacon-module');
            group.style.opacity = '0';
            group.style.transform = 'translateX(20px)';
            group.style.transition = 'all 0.3s ease';
            setTimeout(() => { group.remove(); updateBeaconButtons(); }, 300);
        }

        function updateBeaconButtons() {
            const deleteBtns = document.getElementById('beacon-container').querySelectorAll('.delete-btn');
            deleteBtns.forEach(btn => btn.disabled = (deleteBtns.length <= 1));
        }

        function showToast(msg, isError = false) {
            const toast = document.getElementById('notification');
            toast.textContent = msg;
            toast.className = `notification ${isError ? 'error' : 'success'}`;
            toast.style.display = 'block';
            setTimeout(() => toast.style.top = '20px', 10);
            setTimeout(() => {
                toast.style.top = '-100px';
                setTimeout(() => toast.style.display = 'none', 500);
            }, 3000);
        }

        function saveAllSettings() {
            const ceInputs = document.querySelectorAll('.ce-pin');
            const csnInputs = document.querySelectorAll('.csn-pin');
            let ceList = [], csnList = [];
            let hasNrfError = false;

            ceInputs.forEach((el, idx) => {
                const ce = el.value;
                const csn = csnInputs[idx].value;
                if (ce === "" || csn === "") hasNrfError = true;
                ceList.push(ce);
                csnList.push(csn);
            });

            if (hasNrfError) {
                showToast("Please fill all CE/CSN pins!", true);
                switchTab('tab-nrf');
                return;
            }

            const wifiSsid = encodeURIComponent(document.getElementById('wifi-ssid').value);
            const wifiPassValue = document.getElementById('wifi-pass').value;
            
            if (state.ap === 0 && wifiPassValue.length > 0 && wifiPassValue.length < 8) {
                showToast("WiFi Password must be at least 8 characters!", true);
                switchTab('tab-general');
                return;
            }
            
            const wifiPass = encodeURIComponent(wifiPassValue);

            const beaconInputs = document.querySelectorAll('.beacon-ssid');
            let beaconSsids = [];
            beaconInputs.forEach(mod => {
                const val = mod.value.trim();
                if (val !== "") beaconSsids.push(val);
            });

            const url = `/set_settings?logo=${state.logo}&display=${state.display}&button=${state.button}&sweep=${state.sweep}&pa=${state.pa}&bt_method=${state.bt}&drone_method=${state.drone}&misc_method=${state.misc}&ssid=${wifiSsid}&password=${wifiPass}&ap=${state.ap}` + 
                        (beaconSsids.length > 0 ? `&beacon=${beaconSsids.join('|')}` : '') +
                        `&ce=${ceList.join('|')}&csn=${csnList.join('|')}`;

            fetch(url)
                .then(response => {
                    if (response.ok) {
                        window.location.href = '/';
                    } else {
                        showToast("Failed to save settings", true);
                    }
                })
                .catch(() => {
                    showToast("Error saving settings", true);
                });
        }

        function applyServerData() {
            const rawData = "[||]EdItAbLe TeXt[||]";
            
            if (rawData !== "[||]" + "EdItAbLe TeXt" + "[||]") {
                const pairs = rawData.split(';');
                
                pairs.forEach(pair => {
                    const [key, val] = pair.split('=');
                    if (!key || val === undefined) return;
                    
                    const k = key.trim();
                    const v = val.trim();

                    if (state.hasOwnProperty(k) && k !== 'ap') {
                        setOpt(k, parseInt(v, 10));
                    } 
                    else if (k === 'ssid') {
                        document.getElementById('wifi-ssid').value = v;
                    }
                    else if (k === 'password') {
                        document.getElementById('wifi-pass').value = v;
                    }
                    else if (k === 'ap') {
                        state.ap = parseInt(v, 10);
                        document.getElementById('ap-disable').checked = (state.ap === 1);
                        toggleApStatus();
                    }
                    else if (k === 'beacon') {
                        document.getElementById('beacon-container').innerHTML = '';
                        v.split('|').forEach(ssid => addBeaconModule(ssid));
                    }
                    else if (k === 'ce') {
                        const ceArr = v.split('|');
                        const csnArr = (pairs.find(p => p.startsWith('csn=')) || '').split('=')[1]?.split('|') || [];
                        
                        document.getElementById('nrf-container').innerHTML = '';
                        ceArr.forEach((ce, i) => addNrfModule(ce, csnArr[i] || ''));
                    }
                });
            }
        }

        addNrfModule();
        addBeaconModule();
        
        applyServerData();

    </script>
</body>
</html>
)rawliteral";

static const char *const html_webserial = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <style>
        :root {
            --bg-primary: #0d1117;
            --bg-secondary: #161b22;
            --bg-card: #21262d;
            --border: #30363d;
            --text-primary: #ffffff;
            --text-secondary: #8b949e;
            --accent: #58a6ff;
            --danger: #f85149;
            --warning: #f0883e;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', system-ui, sans-serif;
            -webkit-tap-highlight-color: transparent;
        }
        
        body {
            background: var(--bg-primary);
            color: var(--text-primary);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 10px;
            opacity: 0;
            animation: fadeIn 0.6s ease-out forwards;
            overflow-x: hidden;
        }
        
        @keyframes fadeIn {
            to { opacity: 1; }
        }
        
        .container {
            width: 100%;
            max-width: 800px;
            height: auto;
            min-height: calc(100vh - 20px);
            padding: 15px;
            border-radius: 12px;
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
            display: flex;
            flex-direction: column;
            gap: 15px;
        }
        
        .header {
            text-align: center;
            flex-shrink: 0;
            padding: 10px 0;
        }
        
        .header h1 {
            font-size: clamp(1.5rem, 4vw, 2rem);
        }
        
        .terminal-container {
            flex: 1;
            min-height: 300px;
            max-height: 50vh;
            background: var(--bg-card);
            border: 1px solid var(--border);
            border-radius: 8px;
            overflow: hidden;
            display: flex;
            flex-direction: column;
            position: relative;
        }
        
        .terminal-wrapper {
            flex: 1;
            overflow-y: auto;
            padding: 15px;
            -webkit-overflow-scrolling: touch;
        }
        
        .terminal {
            font-family: 'Courier New', monospace;
            font-size: 13px;
            white-space: pre-wrap;
            word-break: break-word;
            line-height: 1.4;
            display: flex;
            flex-direction: column;
            min-height: min-content;
        }
        
        .terminal-line {
            margin-bottom: 8px;
            min-height: 18px;
            word-wrap: break-word;
        }
        
        .input-group {
            display: flex;
            gap: 10px;
            flex-shrink: 0;
            width: 100%;
        }
        
        .input {
            flex: 1;
            min-width: 0;
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 16px;
            border-radius: 8px;
            font-family: monospace;
            font-size: 16px;
            outline: none;
            -webkit-appearance: none;
            touch-action: manipulation;
        }
        
        .input:focus {
            border-color: var(--accent);
            box-shadow: 0 0 0 2px rgba(88, 166, 255, 0.2);
        }
        
        .btn {
            background: var(--bg-card);
            border: 1px solid var(--accent);
            color: var(--text-primary);
            padding: 14px 20px;
            border-radius: 8px;
            font-size: 16px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            flex-shrink: 0;
            min-width: 80px;
            touch-action: manipulation;
        }
        
        .btn:hover,
        .btn:active {
            background: var(--accent);
            border-color: var(--accent);
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(88, 166, 255, 0.2);
        }
        
        .back-btn {
            background: var(--bg-card);
            border: 1px solid var(--border);
            color: var(--text-primary);
            padding: 14px 20px;
            border-radius: 8px;
            font-size: 16px;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            text-align: center;
            width: 100%;
            touch-action: manipulation;
            margin-top: 10px;
        }
        
        .back-btn:hover,
        .back-btn:active {
            background: var(--bg-secondary);
            border-color: var(--accent);
            transform: translateY(-1px);
        }
        
        .prompt {
            color: #2ea043;
            font-weight: bold;
        }
        
        .error {
            color: var(--danger);
        }

        .terminal-wrapper::-webkit-scrollbar {
            width: 6px;
        }
        
        .terminal-wrapper::-webkit-scrollbar-track {
            background: var(--bg-card);
            border-radius: 3px;
        }
        
        .terminal-wrapper::-webkit-scrollbar-thumb {
            background: var(--border);
            border-radius: 3px;
        }
        
        .terminal-wrapper::-webkit-scrollbar-thumb:hover {
            background: var(--text-secondary);
        }

        @media (max-width: 768px) {
            .container {
                padding: 12px;
                gap: 12px;
                height: auto;
                min-height: calc(100vh - 20px);
            }
            
            .header {
                padding: 5px 0;
            }
            
            .terminal-container {
                max-height: 50vh;
                min-height: 250px;
            }
            
            .terminal-wrapper {
                padding: 12px;
            }
            
            .input-group {
                flex-direction: column;
                gap: 8px;
            }
            
            .input {
                padding: 16px;
                font-size: 16px;
            }
            
            .btn {
                padding: 16px;
                width: 100%;
                min-width: auto;
            }
            
            .back-btn {
                padding: 16px;
            }
            
            .terminal {
                font-size: 14px;
            }
        }
        
        @media (max-width: 480px) {
            body {
                padding: 8px;
            }
            
            .container {
                padding: 10px;
                border-radius: 8px;
            }
            
            .header h1 {
                font-size: 1.3rem;
            }
            
            .terminal-container {
                max-height: 45vh;
                min-height: 200px;
            }
            
            .input, .btn, .back-btn {
                padding: 14px;
            }
            
            .terminal {
                font-size: 13px;
            }
        }

        @supports (-webkit-touch-callout: none) {
            .input {
                font-size: 16px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Serial Terminal</h1>
        </div>
        
        <div class="terminal-container">
            <div class="terminal-wrapper">
                <div class="terminal" id="terminal"></div>
            </div>
        </div>
        
        <div class="input-group">
            <input type="text" class="input" id="commandInput" placeholder="Type command..." autocomplete="off" autocapitalize="off" autocorrect="off" spellcheck="false">
            <button class="btn" id="sendButton">Send</button>
        </div>
        
        <button class="back-btn" onclick="location.href='/'">← Back to Main Menu</button>
    </div>

    <script>
        const terminal = document.getElementById('terminal');
        const input = document.getElementById('commandInput');
        const sendButton = document.getElementById('sendButton');
        const terminalWrapper = document.querySelector('.terminal-wrapper');
        
        let history = [];
        let historyIndex = -1;
        let isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);

        function preventContainerResize() {
            const container = document.querySelector('.container');
            container.style.height = isMobile ? 'auto' : '80vh';
            container.style.minHeight = isMobile ? 'calc(100vh - 20px)' : '80vh';
        }

        window.addEventListener('load', async () => {
            preventContainerResize();
            input.focus();

            if (isMobile) {
                setTimeout(() => {
                    input.blur();
                }, 100);
            }
            
            await sendAutoHelp();
        });
        
        window.addEventListener('resize', preventContainerResize);
        
        async function sendAutoHelp() {
            addCommand('help');
            
            try {
                const response = await fetch('/WebCommand', {
                    method: 'POST',
                    body: new URLSearchParams({ command: 'help' })
                });
                
                const text = await response.text();
                const lastOk = text.lastIndexOf('ok');
                const output = lastOk !== -1 ? text.substring(0, lastOk).trim() : text;
                
                addResponse(output);
                scrollToBottom();
            } catch (error) {
                addError('Network connection failed');
                scrollToBottom();
            }
        }

        input.addEventListener('keydown', function(e) {
            if (e.key === 'Enter') {
                sendCommand();
                if (isMobile) {
                    input.blur();
                }
            } else if (e.key === 'ArrowUp') {
                e.preventDefault();
                if (history.length > 0) {
                    if (historyIndex === -1) {
                        historyIndex = history.length - 1;
                    } else if (historyIndex > 0) {
                        historyIndex--;
                    }
                    input.value = history[historyIndex] || '';
                }
            } else if (e.key === 'ArrowDown') {
                e.preventDefault();
                if (historyIndex < history.length - 1) {
                    historyIndex++;
                    input.value = history[historyIndex] || '';
                } else {
                    historyIndex = -1;
                    input.value = '';
                }
            }
        });
        
        sendButton.addEventListener('click', sendCommand);

        if (isMobile) {
            terminalWrapper.addEventListener('click', () => {
                input.focus();
            });
        }
        
        function addCommand(command) {
            const div = document.createElement('div');
            div.className = 'terminal-line';
            div.innerHTML = `<span class="prompt">$</span> ${command}`;
            terminal.appendChild(div);
        }
        
        function addResponse(response) {
            const lines = response.split('\n');
            lines.forEach(line => {
                if (line.trim() !== '') {
                    const div = document.createElement('div');
                    div.className = 'terminal-line';
                    div.textContent = line;
                    terminal.appendChild(div);
                }
            });
        }
        
        function addError(error) {
            const div = document.createElement('div');
            div.className = 'terminal-line';
            div.innerHTML = `<span class="error">${error}</span>`;
            terminal.appendChild(div);
        }
        
        async function sendCommand() {
            const command = input.value.trim();
            if (!command) return;
            
            history.push(command);
            historyIndex = -1;
            
            addCommand(command);
            input.value = '';
            
            try {
                const response = await fetch('/WebCommand', {
                    method: 'POST',
                    body: new URLSearchParams({ command })
                });
                
                const text = await response.text();
                const lastOk = text.lastIndexOf('ok');
                const output = lastOk !== -1 ? text.substring(0, lastOk).trim() : text;
                
                addResponse(output);
                const emptyLine = document.createElement('div');
                emptyLine.className = 'terminal-line';
                emptyLine.style.height = '8px';
                terminal.appendChild(emptyLine);
            } catch (error) {
                addError('Network connection failed');
            }
            
            scrollToBottom();

            if (isMobile) {
                setTimeout(() => {
                    input.focus();
                }, 100);
            }
        }
        
        function scrollToBottom() {
            requestAnimationFrame(() => {
                terminalWrapper.scrollTop = terminalWrapper.scrollHeight;
            });
        }
    </script>
</body>
</html>
)rawliteral";

#endif
