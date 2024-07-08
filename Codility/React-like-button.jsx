import cx from 'classnames';
import { Component } from 'react';

export default class LikeButton extends Component {
  // Initialize state in the constructor
  constructor(props) {
    super(props);
    this.state = {
      likes: 100, // State variable to track the number of likes
      liked: false // State variable to track if the button is liked
    };
  }

  // Method to handle button click
  handleLikeClick = () => {
    this.setState((prevState) => ({
      likes: prevState.liked ? prevState.likes - 1 : prevState.likes + 1,
      liked: !prevState.liked
    }));
  };

  render() {
    const { likes, liked } = this.state;
    const buttonClass = cx('like-button', { liked });

    return (
      <>
        <div>
          <h2>Like Button</h2>
          <button className={buttonClass} onClick={this.handleLikeClick}>
            Like | {likes}
          </button>
        </div>
        <style>{`
          .like-button {
            font-size: 1rem;
            padding: 5px 10px;
            color: #585858;
          }
          .liked {
            font-weight: bold;
            color: #1565c0;
          }
        `}</style>
      </>
    );
  }
}
