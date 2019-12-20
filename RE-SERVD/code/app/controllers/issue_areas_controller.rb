class IssueAreasController < ApplicationController
  before_action :set_issue_area, only: [:show, :edit, :update, :destroy]

  # GET /issue_areas
  # GET /issue_areas.json
  def index
    @issue_areas = IssueArea.all
  end

  # GET /issue_areas/1
  # GET /issue_areas/1.json
  def show
  end

  # GET /issue_areas/new
  def new
    @issue_area = IssueArea.new
  end

  # GET /issue_areas/1/edit
  def edit
  end

  # POST /issue_areas
  # POST /issue_areas.json
  def create
    @issue_area = IssueArea.new(issue_area_params)

    respond_to do |format|
      if @issue_area.save
        format.html { redirect_to @issue_area, notice: 'Issue area was successfully created.' }
        format.json { render :show, status: :created, location: @issue_area }
      else
        format.html { render :new }
        format.json { render json: @issue_area.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /issue_areas/1
  # PATCH/PUT /issue_areas/1.json
  def update
    respond_to do |format|
      if @issue_area.update(issue_area_params)
        format.html { redirect_to @issue_area, notice: 'Issue area was successfully updated.' }
        format.json { render :show, status: :ok, location: @issue_area }
      else
        format.html { render :edit }
        format.json { render json: @issue_area.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /issue_areas/1
  # DELETE /issue_areas/1.json
  def destroy
    @issue_area.destroy
    respond_to do |format|
      format.html { redirect_to issue_areas_url, notice: 'Issue area was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private


    # Use callbacks to share common setup or constraints between actions.
    def set_issue_area
      @issue_area = IssueArea.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def issue_area_params
      params.require(:issue_area).permit(:name)
    end
end
