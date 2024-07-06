import { Component } from '@angular/core';

@Component({
    selector: 'like-button',
    template: `
        <button  class ="like-button"

         [ngClass]="{'liked': isLiked}"

         (click)="onclick()">

        Like | {{currentcount}}
        </button>
    `,
    styles: [`
        .like-button {
            font-size: 1rem;
            padding: 5px 10px;
            color:  #585858;
        }

        .liked {
            font-weight: bold;
            color: #1565c0;
        }
    `]
})

export class LikeButtonComponent {
    public initialCount = 100;
    public isLiked = false;
    public currentcount  = this.initialCount;

    onclick(): void{
        if(this.isLiked){
            this.currentcount = this.initialCount;
        }
        else{
            this.currentcount = this.initialCount +1 ;
        }
       this.isLiked  = !this.isLiked;
    }
}