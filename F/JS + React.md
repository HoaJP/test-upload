=================JS=================
1. Spead: khi truyền đối số
2. Rest: kết hợp với destruturing để định nghĩa ra biến


=================React===============
1. React.createElement(type, props, children, n)

2. useState hook
- Component được re-render sau khi 'setState'
- Initial state chỉ dùng cho lần đầu 
- Set state với callback
    setCounter(preveState => preveState+1)
- Initial state với callback (lấy giá trị return của callback làm initial state) => k cần tính lại
- Set state là thay thế state bằng giá trị mới

3. useEffect hook: thứ tự chạy: 3:52 useLayoutEffect
    a. callback được gọi mỗi khi component mounted
    ==================
- useEffect(callback)
    + gọi callback mỗi khi component re-render
    + gọi callback sau khi component thêm element vào DOM
- useEffect(callback, [])
    + chỉ gọi callback một lần sau khi component mounted
- useEffect(callback, [deps])
    + callback được gọi khi deps thay đổi
==> 1 Cập nhật lại State 
    2 Cập nhật DOM (mutated)
    3 Render lại UI
    4 Gọi CleanUp nếu deps thay đổi
    5 Gọi useEffect callback

4. cleanUp function
- cleanUp được gọi trước khi component unmount để tránh rò rỉ bộ nhớ
- cleanUp được gọi trước khi callback được gọi (trừ lần mounted)

5. useLayoutEffect
-Thứ tự:
    1 Cập nhật lại state
    2 Cập nhật DOM (mutated)
    3 Gọi cleanup nếu deps thay đổi (sync)
    4 Gọi useLayoutEffect callback (sync)
    5 Render lại UI

6. useRef:
    Khi chúng ta dùng useRef để lưu giá trị, thì khi phải render lại một function component, giá trị đã lưu sẽ không bị thay đổi, mà vẫn giữ được giá trị đã lưu trước đó.

7. useCallback
- useCallback là một hook giúp chúng ta lưu lại một function, giúp chúng ta tránh việc tạo ra một function mới không cần thiết khi re-render
- dùng reference type và React memo()

8. React memo : chỉ re-render lại component khi một trong các prop của component thay đổi
9. useMemo: tránh thực hiện lại một logic nào đó không cần thiết
- useMemo(cb, deps) : cách hoạt động tương tự useEffect
10. useReducer
- useReducer là một hook giúp chúng ta quản lý state phức tạp
- useReducer có 2 tham số: reducer và initialState
- useReducer được gọi mỗi khi state thay đổi
+ 1. init state: 
  2. action
  <!-- 1, 2 như useState -->
  3. reducer
  4. dispatch
  