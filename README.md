# Tony-s-maze
*Hướng dẫn cài đặt chương trình
  - Tải Code::Blocks 20.03
  - Tải thư viện đồ họa SDL, SDL_image, SDL_ttf, SDL_mixer và cài đặt các đường dẫn vào Code::Blocks
  - Copy link code của github
  - Sử dụng cửa sổ Git Bash, ấn cd + "Tên folder muốn đưa dự án về"
  - Sử dụng lệnh git clone +  https://github.com/scallop200603/Tony-s-maze
  - Copy folder đã chứa đầy đủ file ra ngoài
  - Mở Code::Blocks, ấn "Open an existing project" sau đó tìm tới folder mình vừa cho ra ngoài, ấn vào folder và ấn vào file "obstacle.cbp"
*Mô tả chung về trò chơi, các ý tưởng chính
  - Trò chơi có tên Tony's maze, hãy giúp chú ma Tony thoát khỏi mê cung
  - Sử dụng bàn phím để điều khiển và tránh đụng vào thành mê cung 
*Mô tả các chức năng đã cài đặt, kèm video minh họa (chèn link video youtube)
  - Em có dùng SDL_image và SDL_ttf để làm hiện ra hình ảnh mở đầu và 2 dòng chữ trên đó
  - Bên cạnh đó em dùng thư viện SDL_mixer để tạo âm thanh xuyên suốt trò chơi
  - Sau đó là một loạt các thành mê cung là các SDL_Rect (hình chữ nhật) xuất hiện hỗn độn không có quy luật
  - Sử dụng SDL_WaitEvent bắt sự kiện từ bàn phím
     + Khi ấn mũi tên lên thì Tony sẽ đi lên
     + Khi ấn mũi tên xuống thì Tony sẽ đi xuống
     + Khi ấn mũi tên phải thì Tony sẽ đi sang phải
     + Khi ấn mũi tên trái thì Tony sẽ đi sang trái
 *Link video minh họa: https://www.youtube.com/watch?v=aa1uFTpTgoc
 *Các kỹ thuật lập trình có trong dự án: con trỏ, struct, thư viện đồ họa SDL, mảng một chiều
 *Kết luận: với thư viện đồ họa SDL kết hợp với những kiến thức về C++(con trỏ, mảng, struct,..), ta có thể làm được những game từ đơn giản tới phức tạp, trong quá trình cài đặt các thư viện đồ họa cần phải chú ý các đường dẫn tới file chứa các mục phải chính xác, bên cạnh đó nên chia dự án thành các file nhỏ hơn để code dễ nhìn và ngắn gọn hơn
 *Hướng phát triển: sau này sẽ có thêm phần xử lý sự kiện từ chuột (SDL_MouseClickEvent) và phần introduction ở phần mở đầu
 *Điều tâm đắc nhất sau dự án: biết sử dụng cơ bản thư viện đồ họa, đây cũng là một cơ hội để phô diễn những kỹ năng mà mình đã tích lũy được suốt thời gian một năm học qua, biết cách xử lý vấn đề, không còn quá hoảng loạn khi gặp sự cố
